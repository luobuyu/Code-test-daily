#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
ll f[maxn << 2];
void init(int n)
{
    // 隔项差分
    for(int m = 3; m <= n; m++)
    {
        for(int a = m; a <= n; a += m)
        {
            f[a+3]++;   // am
            f[a + m + 1]--; // (a+1)m+1
            f[a + m + 2]--; // (a+1)m+2
            f[a + m * 2]++; // (a+2)m
        }
    }
    // 差分
    for(int i = 3; i <= n; i++)
    {
        f[i] += f[i - 2]; 
    }
    // 原数组
    for(int i = 2; i <= n; i++)
    {
        f[i] += f[i - 1];
    }
    f[0] = 0;
    // 前缀和
    for(int i = 1; i <= n; i++)
    {
        f[i] += f[i - 1];
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
    scanf("%d", &t);
    init(maxn - 5);
    for (int tcase = 1; tcase <= t; tcase++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("Case #%d: %lld\n", tcase, f[r] - f[l-1]);
    }
    return 0;
}