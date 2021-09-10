#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 5e5 + 10;
const int maxm = 5e5 + 10;
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
int t, n, m, k, s;

struct Edge
{
    int v, next;
} edge[maxm << 1];
int head[maxn], cnt;
bool vis[maxn];
inline void addEdge(int u, int v)
{
    ++cnt;
    edge[cnt] = {v, head[u]};
    head[u] = cnt;
}

int fa[20][maxn], dep[maxn];
// 求出深度
void dfs(int u, int p)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == p)
            continue;
        dep[v] = dep[u] + 1;
        fa[0][v] = u;
        dfs(v, u);
    }
}

void build()
{
    for (int j = 1; j <= 17; j++)
        for (int i = 1; i <= n; i++)
            fa[j][i] = fa[j - 1][fa[j - 1][i]];
}

int query(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    int tmp = dep[u] - dep[v];
    for (int i = 17; i >= 0; i--)
    {
        if (tmp >= (1 << i))
        {
            u = fa[i][u];
            tmp -= (1 << i);
        }
    }
    if(u == v)
        return u;
    for (int i = 17; i >= 0; i--)
    {
        if (fa[i][u] != fa[i][v])
        {
            u = fa[i][u];
            v = fa[i][v];
        }
    }
    return fa[0][u];
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
    n = read(), m = read(), s = read();
    for (int i = 1, u, v; i < n; i++)
    {
        u = read(), v = read();
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(s, 0);
    build();

    for (int i = 1, u, v; i <= m; i++)
    {
        u = read(), v = read();
        printf("%d\n", query(u, v));
    }
    return 0;
}