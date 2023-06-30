// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{
    static string buf_line;
    static int _i;
    static int _n;

    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        char ch = buf_line[_i++];
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = buf_line[_i++];
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = buf_line[_i++];
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

//     int dp[100000][2] = {};
//     int v, ans;
//     string s;
//     for (; getline();)
//     {
//         for (int i = 0; read(v); ++i)
//         {
//             if (i == 0)
//             {
//                 dp[0][0] = v;
//                 dp[0][1] = 0;
//                 ans = v;
//             }
//             else
//             {
//                 dp[i][0] = max(dp[i - 1][0] + v, v);
//                 dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + v);
//                 ans = max(ans, max(dp[i][0], dp[i][1]));
//             }
//         }
//         cout << ans << endl;
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
    const static int maxn = (1 << 16);
    const int INF = 0x3f3f3f3f;

    int minimumIncompatibility(vector<int> &nums, int k)
    {
        static int mp[maxn];
        int n = nums.size();
        int m = n / k;
        int ss = (1 << n);
        memset(mp, -1, sizeof(mp));
        sort(nums.begin(), nums.end());
        for (int i = 1; i < ss; ++i)
        {
            if (__builtin_popcount(i) != m)
                continue;
            int pre = -1;
            bool flag = true;
            int minx = n, maxx = 0;
            for (int j = 0; j < n; ++j)
            {
                if (i >> j & 1)
                {
                    if (nums[j] == pre)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        pre = nums[j];
                    }
                    minx = min(minx, nums[j]);
                    maxx = max(maxx, nums[j]);
                }
            }
            if (flag)
                mp[i] = maxx - minx;
        }

        static int dp[maxn];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < ss; ++i)
        {
            if (dp[i] == INF)
                continue;
            int pre = -1;
            int mask = 0;
            for (int j = 0; j < n; ++j)
            {
                if (((i >> j) & 1) == 0 && nums[j] != pre)
                {
                    mask |= (1 << j);
                    pre = nums[j];
                }
            }
            if (__builtin_popcount(mask) < m)
                continue;
            for (int sub = mask; sub; sub = (sub - 1) & mask)
            {
                if (mp[sub] != -1)
                {
                    dp[i | sub] = min(dp[i | sub], dp[i] + mp[sub]);
                }
            }
        }
        if (dp[ss - 1] == INF)
            return -1;
        return dp[ss - 1];
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
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    solution.minimumIncompatibility(a, 8);
    return 0;
}