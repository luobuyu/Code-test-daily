// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
namespace FAST_IO
{
    static string buf_line;
    static int _i;
    static int _n;
    static char _ch;
    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        _ch = buf_line[_i++];
        while (_ch < '0' || _ch > '9')
        {
            if (_ch == '-')
                flag = -1;
            _ch = buf_line[_i++];
        }
        while (_ch >= '0' && _ch <= '9')
        {
            x = (x << 3) + (x << 1) + (_ch ^ 48), _ch = buf_line[_i++];
        }
        x *= flag;
        return true;
    }

    template <class T, class... _T>
    inline bool read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline bool getline()
    {
        if (!getline(cin, buf_line))
            return false;
        _i = 0, _n = buf_line.length();
        return true;
    }
    template <class T>
    inline void show(T *a, int n)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            cout << a[i];
        }
        cout << "]";
    }

    bool endofl()
    {
        if (_i >= _n)
            return true;
        if (_i == 0)
            return false;
        if (buf_line[_i - 1] == ']')
        {
            _i++;
            return true;
        }
        return false;
    }

    template <class T, std::size_t Num>
    inline void show(T a[][Num], int n, int m)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            show(a[i], m);
        }
        cout << "]";
    }

} // namespace FAST_IO
using namespace FAST_IO;

// int init = []
// {
//     /*********** fast_read ***************/
//     freopen("user.out", "w", stdout);
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     /*************************************/

//     while (true)
//     {
//         if (!getline())
//             break;

//         getline();
//     }
//     exit(0);
//     return 0;
// }();

auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    vector<int> pre;
    vector<pair<int, int>> dp; // 高度，下标
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        auto old = envelopes;
        int len = 1, n = envelopes.size();
        pre.resize(n, -1);
        dp.resize(n + 1, {0, 0});
        sort(envelopes.begin(), envelopes.end(), [&](const vector<int> &x, const vector<int> &y)
             { if(x[0] != y[0]) return x[0] < y[0];
             else return x[1] > y[1]; });
        dp[0] = {envelopes[0][1], 0};
        for (int i = 1; i < n; ++i)
        {
            if (envelopes[i][1] > dp[len - 1].first)
            {
                pre[i] = dp[len - 1].second;
                dp[len++] = {envelopes[i][1], i};
            }
            else
            {
                int index = lower_bound(dp.begin(), dp.begin() + len, make_pair(envelopes[i][1], i),
                                        [&](const pair<int, int> &x, const pair<int, int> &y)
                                        {
                                            return x.first < y.first;
                                        }) -
                            dp.begin();
                pre[i] = pre[dp[index].second];
                dp[index] = {envelopes[i][1], i};
            }
        }
        vector<int> ans;
        int tmp = dp[len - 1].second;
        bool flag = false;
        while (tmp != -1)
        {
            ans.push_back(tmp);
            tmp = pre[tmp];
        }

        reverse(ans.begin(), ans.end());
        for (int i = 0; i < len; ++i)
        {
            cout << envelopes[ans[i]][0] << ", " << envelopes[ans[i]][1] << endl;
        }
        return len;
    }
};

int t, n, m, k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<vector<int>> a = {{1, 5}, {3, 7}, {4, 0}, {9, 5}};
    solution.maxEnvelopes(a);
    return 0;
}