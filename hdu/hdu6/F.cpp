#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 2e5 + 10;
const int maxm = 2e5 + 10;
int t, n, m, k;
int sum[maxn][3];
int one, zero;
ll ans;
struct Edge
{
    int v, next;
    ll w;
} edge[maxm << 1];
int head[maxn], cnt;
bool vis[maxn];
inline void addEdge(int u, int v, ll w = 0)
{
    ++cnt;
    edge[cnt] = {v, head[u], w};
    head[u] = cnt;
}

int fa[maxn];
int findFa(int u) { return u == fa[u] ? u : (fa[u] = findFa(fa[u])); }

void init(int n)
{
    one = zero = ans = cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i][0] = sum[i][1] = 0;
        fa[i] = i;
        head[i] = 0;
    }
}

void dfs(int u, int p)
{
    sum[u][0] = sum[u][1] =  0;
    sum[u][sum[u][2]]++;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == p) continue;
        dfs(v, u);
        sum[u][0] += sum[v][0];
        sum[u][1] += sum[v][1];
    }

    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v==p)
            continue;
        ans = (ans + 1LL * sum[v][0] * (one - sum[v][1]) % mod * edge[i].w % mod) % mod;
        ans = (ans + 1LL * sum[v][1] * (zero - sum[v][0]) % mod * edge[i].w % mod) % mod;
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
    while (t--)
    {
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &sum[i][2]);
            if (sum[i][2])
                one++;
            else zero++;
        }
        int u, v;
        ll w = 1;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            w = w * 2 % mod;
            int up = findFa(u), vp = findFa(v);
            if(up == vp)
                continue;
            fa[up] = vp;
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        dfs(1, -1);
        printf("%lld\n", ans);
    }
    return 0;
}