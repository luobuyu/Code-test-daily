#include <bits/stdc++.h>
using namespace std;
const int N = 25e4 + 5, M = 505;
int f[N * 2], s[M], a[M][M], b[M][M];
long long ans;
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
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", a[i] + j);
            if (!a[i][j])
                a[i][j] = -1;
            b[i][j] = a[i][j] + b[i - 1][j];
        }
    s[0] = N;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int pre = 1, k;
            for (k = 1; k <= m; k++)
            {
                if (a[i][k] != 1 || a[j][k] != 1)
                {
                    for (int l = pre; l <= k; l++)
                        if (b[j][l] - b[i - 1][l] == j - i + 1)
                            f[s[l]]--;
                    pre = k + 1;
                    s[k] = N;
                    continue;
                }
                if (b[j][k] - b[i - 1][k] == j - i + 1)
                    ans += f[s[k - 1]] + f[s[k - 1] + 1] + f[s[k - 1] - 1];
                s[k] = s[k - 1] + b[j - 1][k] - b[i][k];
                if (b[j][k] - b[i - 1][k] == j - i + 1)
                    f[s[k]]++;
            }
            for (int l = pre; l <= m; l++)
                if (b[j][l] - b[i - 1][l] == j - i + 1)
                    f[s[l]]--;
        }
    }
    printf("%lld", ans);
    return 0;
}