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
int a[maxn], b[maxn];
int c[maxn << 1], tot = 0;

int fa[maxn << 1];
bool vis[maxn << 1];
int findFa(int u)
{
    return (u == fa[u] ? u : fa[u] = findFa(fa[u]));
}

void unite(int u, int v)
{
    int up = findFa(u);
    int vp = findFa(v);
    if(up == vp)
    {
        vis[up] = true;
    }
    else
    {
        fa[up] = vp;
        if(vis[up])
            vis[vp] = true;
    }
}

void init(int n)
{
    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    memset(vis, false, sizeof(vis));
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
    for(int tcase = 1; tcase <= t; tcase++)
    {
        scanf("%d", &n);
        tot = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &a[i], &b[i]);
            c[++tot] = a[i];
            c[++tot] = b[i];
        }
        sort(c+1, c+1+tot);
        tot = unique(c + 1, c + 1 + tot) - c - 1;
        init(tot);
        for (int i = 1; i <= n; i++)
        {
            int x = lower_bound(c + 1, c + tot + 1, a[i]) - c;
            int y = lower_bound(c + 1, c + tot + 1, b[i]) - c;
            unite(x, y);
        }

        int ans = tot;
        for (int i = 1; i <= tot; i++)
        {
            if(!vis[i] && fa[i] == i)
            {
                ans--;
            }
        }
        printf("Case #%d: %d\n", tcase, ans);
    }
    return 0;
}