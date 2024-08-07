// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll long long
#define PII pair<int, int>
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
    const int INF = 0x3f3f3f3f;
    // 找大于等于 target 的
    int getIndex(vector<int> &days, int start, int target)
    {
        int index = lower_bound(days.begin() + start, days.end(), target) - days.begin();
        return index;
    }
    int getIndex2(vector<int> &days, int end, int target)
    {
        int index = lower_bound(days.begin(), days.begin() + end, target) - days.begin();
        return index;
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        int m = costs.size();
        // dp[i] i -> 最后
        // dp[i] = dp[i + 1] dp[i + 7] dp[i + 30]
        vector<vector<int>> dp(n + 1, vector<int>(4, INF));
        dp[0][1] = costs[0];
        dp[0][2] = costs[1];
        dp[0][3] = costs[2];
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = min(dp[i][0], dp[getIndex2(days, i, days[i] - 1)][1]);
            dp[i][0] = min(dp[i][0], dp[getIndex2(days, i, days[i] - 7)][2]);
            dp[i][0] = min(dp[i][0], dp[getIndex2(days, i, days[i] - 30)][3]);
            int tmp = min(dp[i - 1][0], min(dp[i - 1][1], min(dp[i - 1][2], dp[i - 1][3])));
            dp[i][1] = tmp + costs[0];
            dp[i][2] = tmp + costs[1];
            dp[i][3] = tmp + costs[2];
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], min(dp[n - 1][2], dp[n - 1][3])));
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
    vector<int> a = {1, 4, 6, 7, 8, 20};
    vector<int> b = {2, 7, 15};
    solution.mincostTickets(a, b);

    return 0;
}