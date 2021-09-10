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
const int maxn = 1e6 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
int color[maxn];
int dp[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
            a[i] = n - a[i] + 1;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i] = INF;
        }
        dp[0] = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int pos = lower_bound(dp + 1, dp + 1 + n, a[i]) - dp;
            color[i] = pos;
            ans = max(ans, pos);
            dp[pos] = a[i];
        }
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", color[i], " \n"[i == n]);
        }
    }
    return 0;
}