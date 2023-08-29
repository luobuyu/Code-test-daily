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
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int backpack(vector<int> &nums, int size)
    {
        // dp[i][j] = (dp[i-1][j], dp[i-1][j - size[i]])
        vector<int> dp(size + 1);
        dp[0] = 1;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = size; j >= nums[i]; --j)
            {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[size];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // sum - 2x = target, x = (sum-target)/2
        int sum = 0;
        for (auto &x : nums)
            sum += x;
        if ((sum - target) < 0 || (sum - target) & 1)
            return 0;
        return dfs(nums, target, sum, 0, 0);
    }

    int dfs(vector<int> &nums, int target, int extra, int sum, int step)
    {
        if (sum + extra < target || sum - extra > target)
            return 0;
        if (step >= nums.size())
        {
            if (sum == target)
                return 1;
            else
                return 0;
        }

        int ans = 0;
        ans += dfs(nums, target, extra - nums[step], sum + nums[step], step + 1);
        ans += dfs(nums, target, extra - nums[step], sum - nums[step], step + 1);
        return ans;
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
    vector<int> a = {1, 1, 1, 1, 1};
    solution.findTargetSumWays(a, 3);
    return 0;
}