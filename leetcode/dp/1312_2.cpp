// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{
    static char buf_line[10000];
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
        if (!gets(buf_line))
            return false;
        _i = 0, _n = strlen(buf_line);
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

int init = []
{
/*********** fast_read ***************/
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("user.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*************************************/
    static const int maxn = 5e2 + 1;
    int dp[maxn][maxn];
    string s;
    int n;
    for (; getline();)
    {
        n = _n - 1;
        for (int i = 1; i <= n; ++i)
        {
            dp[i][i] = 1;
        }
        int ans = 0;
        for (int i = n; i >= 1; --i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (buf_line[i] == buf_line[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[1][n] << "\n";
    }
    exit(0);
    return 0;
}();

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
    const static int maxn = 5e2 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    // 找到最长的回文子序列
    int dp[maxn][maxn] = {};
    int minInsertions(string s)
    {
        int n = s.length();
        for (int i = 1; i <= n; ++i)
        {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; ++len)
        {
            for (int i = 1; i + len - 1 <= n; ++i)
            {
                int j = i + len - 1;
                if (s[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return n - dp[1][n];
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

    return 0;
}