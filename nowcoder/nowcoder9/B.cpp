#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e5 + 10;
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
int a[maxn];

struct Edge
{
    int v, w, next;
} edge[maxm << 1];
int head[maxn], cnt;
bool vis[maxn];
inline void addEdge(int u, int v, int w)
{
    ++cnt;
    edge[cnt] = {v, w, head[u]};
    head[u] = cnt;
}

struct Node
{
    int id;
    ll c, g;
} dp[maxn];

bool cmp(Node a, Node b)
{
    if (a.g > a.c)
        if (b.g > b.c)
            return a.c < b.c;
        else
            return true;
    else if (b.g > b.c)
        return false;
    else
        return a.g > b.g;
}

void dfs(int u, int p)
{
    vector<Node> comp;
    for(int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == p)
            continue;
        dfs(v, u);
        dp[v].id = v;
        dp[v].c += edge[i].w;
        dp[v].g -= edge[i].w;
        if(dp[v].g < 0)
            dp[v].c -= dp[v].g, dp[v].g = 0;
        comp.push_back(dp[v]);
    }
    sort(comp.begin(), comp.end(), cmp);

    dp[u].c = 0;
    ll now = a[u];
    for(int i = 0; i < comp.size(); i++)
    {
        auto v = comp[i];
        now -= v.c;
        if(now < 0)
        {
            dp[u].c -= now;
            now = 0;
        }
        now += v.g;
    }
    dp[u].g = now;
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
        cnt = 0;
        n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read(), head[i] = 0;

        for (int i = 1, u, v, w; i < n; i++)
        {
            u = read(), v = read(), w = read();
            addEdge(u, v, w), addEdge(v, u, w);
        }
        dfs(1, 0);
        printf("%lld\n", dp[1].c);
    }
    return 0;
}