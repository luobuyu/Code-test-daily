#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 10 + 3;
const int maxm = 5e3 + 10;
int t, n, m, k;

set<int> dp[maxn][maxn];
int a[maxn] = {0, 1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 1, 1};
int ans[maxm];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第六场/1005/in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    for (int i = 1; i < maxn; i++)
    {
        int tmp = 0;
        for (int j = i; j <= min(i + 3, maxn - 1); j++)
        {
            tmp = tmp * 10 + a[j];
            if (tmp <= 5000)
                dp[i][j].insert(tmp);
        }
    }


    for (int len = 2; len < maxn; len++)
    {
        for (int i = 1; i + len - 1 < maxn; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                if (dp[i][k].size() && dp[k + 1][j].size())
                {
                    for (auto u : dp[i][k])
                    {
                        for (auto v : dp[k + 1][j])
                        {
                            if (u + v <= 5000)
                                dp[i][j].insert(u + v);
                            if (u * v <= 5000)
                                dp[i][j].insert(u * v);
                        }
                    }
                }
            }
        }
    }



    for (int i = 1; i < maxn; i++)
    {
        for (auto it : dp[1][i])
        {
            if (ans[it] == 0)
            {
                ans[it] = i;
            }
        }
    }
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        if(ans[n] != 0)
        {
            printf("%d\n", ans[n]);
        }
        else
        {
            printf("-1\n");
        }
        }
    return 0;
}