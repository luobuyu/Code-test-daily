// #pragma GCC optimize(2)
#include <bits/stdc++.h>
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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k, v;
int a[maxn][3];
int dp[maxn][maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    read(m, n, t);
    for (int i = 1; i <= t; ++i)
    {
        read(a[i][0], a[i][1], a[i][2]);
    }
    // dp[i][j][k] 表示前 i 个至少装满 j,k 所需要的最小重量
    // dp[i][j][k] = min(dp[i-1][j][k], dp[i - 1][j - aij][k - aik] + aiv);
    // 初始化为无穷大，dp[0][0][0] = 0;
    // 当 j - aij 为负值时，其实表示 aij 可以装满 j，直接用 max(0, j - aij), max(0, k - aik)

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= t; ++i)
    {
        for (int j = m; j >= 0; --j)
        {
            for (int k = n; k >= 0; --k)
            {
                dp[j][k] = min(dp[j][k], dp[max(0, j - a[i][0])][max(0, k - a[i][1])] + a[i][2]);
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}