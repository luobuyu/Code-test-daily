#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e2 + 10;
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
int a[maxn], c[maxn][maxn], dp[maxn][maxn][maxn];
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
    for (int i = 0; i <= maxn - 5; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    t = read();
    while (t--)
    {

        n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        memset(dp, 0, sizeof(dp));
        for (int i = n; i >= 1; i--)
            for (int j = i; j <= n; j++)
                for (int k = i; k <= j; k++)
                {

                    int s = ~a[k] ? a[k] : 1;
                    int end = ~a[k] ? a[k] : n;
                    for (int p = s; p <= end; p++)
                    {
                        dp[i][j][p] = (dp[i][j][p] + 1LL * (i < k ? dp[i][k - 1][p] : 1) * (k < j ? dp[k + 1][j][p + 1] : 1) % mod * c[j - i][k - i]) % mod;
                    }
                }
        printf("%d\n", dp[1][n][1]);
    }
    return 0;
}