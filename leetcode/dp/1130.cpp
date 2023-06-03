// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
int t, n, m, k;
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
    const static int maxn = 4e1 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int dp[maxn][maxn];
    int maxl[maxn][maxn];
    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();
        // 区间 dp
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
            {
                if (i == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = INF;
            }
        for (int i = 0; i < n; ++i)
        {
            int maxx = arr[i];
            for (int j = i; j < n; ++j)
            {
                maxx = max(maxx, arr[j]);
                maxl[i][j] = maxx;
            }
        }
        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                for (int k = i; k < j; ++k)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxl[i][k] * maxl[k + 1][j]);
                    // cout << i << ", " << j << ", " << dp[i][k] << ", " << dp[k + 1][j] << ", " << dp[i][j] << endl;
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<int> a = {6, 15, 5, 2};
    solution.mctFromLeafValues(a);
    return 0;
}