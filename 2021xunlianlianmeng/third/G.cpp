#include <bits/stdc++.h>
#define ll long long
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

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
double a[maxn];
double dp[maxn][maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    for (int x, i = 1; i <= n; i++)
    {
        read(x);
        a[i] = 1.0 * x / 100;
    }
    sort(a + 1, a + 1 + n, [](double x, double y) { return x > y; });
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = (1 - a[i]) * dp[i - 1][0];
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] * a[i] + dp[i - 1][j] * (1 - a[i]);
        }
    }
    double tmp, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp = 0;
        for (int j = 1; j <= i; j++)
        {
            tmp += dp[i][j] * pow(j, 1.0 * j / i);
        }
        ans = max(ans, tmp);
    }
    printf("%.9f", ans);
    return 0;
}
