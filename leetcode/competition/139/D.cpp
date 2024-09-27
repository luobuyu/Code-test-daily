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
    int maxPathLength(vector<vector<int>> &coordinates, int k)
    {
        auto target = coordinates[k];
        auto old = coordinates;
        int len = 1, n = coordinates.size();
        pre.resize(n, -1);
        dp.resize(n + 1, {0, 0});
        sort(coordinates.begin(), coordinates.end(), [&](const vector<int> &x, const vector<int> &y)
             { if(x[0] != y[0]) return x[0] < y[0];
             else return x[1] > y[1]; });
        dp[0] = {coordinates[0][1], 0};
        for (int i = 1; i < n; ++i)
        {
            if (coordinates[i][1] > dp[len - 1].first)
            {
                pre[i] = dp[len - 1].second;
                dp[len++] = {coordinates[i][1], i};
            }
            else
            {
                int index = lower_bound(dp.begin(), dp.begin() + len, make_pair(coordinates[i][1], i),
                                        [&](const pair<int, int> &x, const pair<int, int> &y)
                                        {
                                            return x.first < y.first;
                                        }) -
                            dp.begin();
                int aim_index = dp[index].second;
                if (target[0] == coordinates[aim_index][0] && target[1] == coordinates[aim_index][1])
                {
                    continue;
                }
                else if (coordinates[i][0] == target[0] && coordinates[i][1] == target[1])
                {
                    len = index + 1;
                }
                if (index - 1 >= 0)
                    pre[i] = dp[index - 1].second;
                else
                    pre[i] = -1;
                dp[index] = {coordinates[i][1], i};
            }
        }
        for (int i = len - 1; i >= 0; --i)
        {
            vector<int> ans;
            int tmp = dp[i].second;
            bool flag = false;
            while (tmp != -1)
            {
                if (coordinates[tmp][0] == target[0] && coordinates[tmp][1] == target[1])
                {
                    flag = true;
                }
                ans.push_back(tmp);
                tmp = pre[tmp];
            }
            if (flag)
            {
                reverse(ans.begin(), ans.end());
                len = ans.size();
                for (int i = 0; i < ans.size(); ++i)
                {
                    if (i >= 1)
                    {
                        auto cur = coordinates[ans[i]];
                        auto pre = coordinates[ans[i - 1]];
                        if (cur[0] == pre[0] || cur[1] == pre[1])
                        {
                            len--;
                        }
                    }
                }
                break;
            }
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
    vector<vector<int>> a = {
        {8, 6},
        {8, 0},
        {3, 8},
        {9, 9},
        {4, 4},
        {3, 4}};
    cout << solution.maxPathLength(a, 1) << endl;
    return 0;
}