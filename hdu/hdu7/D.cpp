#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e6 + 10;
const int maxm = 1e5 + 10;
int read()
{
    int x = 0, flag = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    }
    if (flag)
        return -x;
    return x;
}
int t, n, m, k;
int dp[20][maxn], f[20][maxn], nxt[maxn], a, b;
ll ans = 0;
void cnt(int p, int k)
{
    for (int i = 19; i >= 0; i--)
    {
        if ((1 << i) > k)
            continue;
        ans += 2ll * dp[i][p];
        k -= (1 << i);
        p = f[i + 1][p];
    }
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    t = read();
    while (t--)
    {
        m = read(), a = read(), b = read(), n = read();
        ans = 0;
        for (int i = 0; i < n; i++)
            nxt[i] = (1LL * a * i + b) % n, dp[0][i] = (nxt[i] % 2 == 0), f[0][i] = nxt[i];
        ans += m + 1;
        for(int i = 1; i < 20; i++)
        {
            for(int j = 0; j < n; j++)
            {
                f[i][j] = f[i - 1][f[i - 1][j]];
                dp[i][j] = dp[i - 1][j] + dp[i - 1][f[i][j]];
            }
        }
        for (int i = 0; i < 2 * m; i++)
        {
            if (i <= m)
                cnt((i % 2 == 0) ? nxt[i] : i, (i + 1) / 2);
            else
                cnt((i % 2 == 0) ? nxt[i] : i, (2 * m - i + 1) / 2);
        }
        ll al = 1ll * (m + 1) * (m + 1);
        ll tmp = __gcd(ans, al);
        printf("%lld/%lld\n", ans / tmp, al / tmp);
    }
    return 0;
}