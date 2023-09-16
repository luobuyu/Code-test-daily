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
int t, n, m, k;
int a[maxn];
int dp[maxn][maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tcase;
    read(n, k);
    for (int i = 1; i <= n; ++i)
    {
        read(a[i]);
    }
    sort(a + 1, a + n + 1);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= k; ++j)
    {
        dp[0][k] = 1;
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int p = 1; p < i; ++p)
        {
            if (a[i] % a[p])
                continue;
            for (int j = 1; j <= min(k, i - 1); ++j)
            {
                dp[i][j] = (dp[i][j] + dp[p][j - (i - p - 1)]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans + dp[i][k]) % mod;
    }
    cout << ans << endl;
    return 0;
}