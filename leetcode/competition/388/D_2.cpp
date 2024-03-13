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
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;

    long long maximumStrength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> preSum(n + 1);
        for (int i = 1; i <= n; ++i)
            preSum[i] = preSum[i - 1] + nums[i - 1];
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -INF_LL));
        dp[0][0] = 0;
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 0;
        // dp[i][j] = dp[k]
        for (int kk = 1; kk <= k; ++kk)
        {
            for (int i = kk; i <= n - k + kk; ++i)
            {
                for (int j = max(kk - 1, 1); j <= i; ++j)
                {
                    int tmp = (kk & 1 ? 1 : -1);
                    dp[i][kk] = max(dp[i][kk], max(dp[i - 1][kk], dp[j - 1][kk - 1] + tmp * (preSum[i] - preSum[j - 1]) * (k - kk + 1)));
                }
            }
        }
        return dp[n][k];
    }
};
/*
[3,-87,21,-86,44,-36,80]
5

dp[i][j] 表示以 [1, i] 划分 j段，最大值
dp[i][j] = max(dp[i - 1][j], dp[k][j - 1] + (presum[j] - presum[k - 1]) * (j) )
*/

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
    vector<int> a = {1, 2, 3, -1, 2};
    cout << solution.maximumStrength(a, 3) << endl;
    return 0;
}