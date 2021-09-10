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

int head[maxn], cnt;
struct Edge
{
    int v, next;
} edge[maxm << 1];
inline void addEdge(int u, int v)
{
    ++cnt;
    edge[cnt] = {v, head[u]};
    head[u] = cnt;
}
int dis[2][maxn];
int path[maxn];
void dfs(int u, int p, int id)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == p) continue;
        dis[id][v] = dis[id][u] + 1;
        path[v] = u;
        dfs(v, u, id);
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
    n = read(), t = read();
    int u, v;
    for (int i = 1; i < n; i++)
    {
        u = read(), v = read();
        addEdge(u, v);
        addEdge(v, u);
    }
    memset(dis[1], 0x3f, sizeof(dis[1]));
    dis[1][n] = 0;
    dfs(n, -1, 1);
    if(dis[1][1] <= t)
    {
        printf("0\n");
    }
    else
    {
        int now = 1;
        while(t--)
        {
            now = path[now];
        }
        memset(dis[0], 0x3f, sizeof(dis[0]));
        dis[0][now] = 0;
        dfs(now, -1, 0);
        
        int maxx = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dis[0][i] * 2 <= dis[1][i])
            {
                maxx = max(maxx, dis[1][i] / 2 + (dis[1][i] & 1));
            }
        }
        printf("%d\n", maxx);
    }

    return 0;
}