#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 25e4 + 10;
const int maxm = 5e2 + 10;
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
int a[maxm][maxm];
int sum[maxm][maxm];
int tot[maxn << 1];
int s[maxn];
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
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            a[i][j] = read();
            if(!a[i][j])
                a[i][j] = -1;
            sum[i][j] = sum[i - 1][j] + a[i][j];
        }


    ll ans = 0;
    s[0] = maxn;
    for (int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int pre = 1;
            for(int k = 1; k <= m; k++)
            {
                if(a[i][k] != 1 || a[j][k] != 1)
                {
                    for(int l = pre; l <= k; l++)
                    {
                        if(sum[j][l] - sum[i-1][l] == j - i + 1)
                        {
                            tot[s[l]]--;
                        }
                    }
                    pre = k + 1;
                    s[k] = maxn;
                    continue;
                }
                if(sum[j][k] - sum[i-1][k] == j - i + 1)
                {
                    ans += tot[s[k - 1]] + tot[s[k - 1] + 1] + tot[s[k - 1] - 1];
                }
                s[k] = s[k - 1] + sum[j - 1][k] - sum[i][k];
                if (sum[j][k] - sum[i - 1][k] == j - i + 1)
                    tot[s[k]]++;
            }

            for (int l = pre; l <= m; l++)
            {
                if (sum[j][l] - sum[i - 1][l] == j - i + 1)
                {
                    tot[s[l]]--;
                }
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}