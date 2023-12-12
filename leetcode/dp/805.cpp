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
    const int INF = 0x3f3f3f3f;
    bool splitArraySameAverage2(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (auto &x : nums)
            sum += x;
        // sumA / k = (sum - sumA) / (n - k);
        // sumA = sum * k / n
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        dp[0][0] = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = sum; j >= nums[i]; --j)
            {
                for (int k = 1; k <= n; ++k)
                {
                    dp[k][j] |= dp[k - 1][j - nums[i]];
                }
            }
        }
        for (int i = 1; i < n; ++i)
        {
            if (sum * i % n == 0 && dp[i][sum * i / n])
            {
                return true;
            }
        }
        return false;
    }
    bool splitArraySameAverage(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (auto &x : nums)
            sum += x;
        // sumA / k = (sum - sumA) / (n - k);
        // sumA = sum * k / n
        vector<int> dp(sum + 1);
        // dp[j] 第 i 位 1 表示 dp[i][j] true
        dp[0] = 1; // dp[0][0] = true
        for (int i = 0; i < n; ++i)
        {
            for (int j = sum; j >= nums[i]; --j)
            {
                for (int k = 1; k <= n; ++k)
                {
                    dp[j] |= dp[j - nums[i]] << 1;
                }
            }
        }
        for (int i = 1; i < n; ++i)
        {
            if (sum * i % n == 0 && (dp[sum * i / n] >> (i - 1)) & 1)
            {
                return true;
            }
        }
        return false;
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
    vector<int> a = {17, 3, 7, 12, 1};
    cout << solution.splitArraySameAverage(a) << endl;

    return 0;
}