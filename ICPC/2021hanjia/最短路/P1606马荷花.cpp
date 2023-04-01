#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flags = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flags = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flags;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 100003;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 40 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

int head[maxn * maxn], cnt;
struct Edge
{
    int u, v, w, next;
} edge[maxm << 1];
inline void addEdge(int u, int v, int w)
{
    edge[++cnt] = {u, v, w, head[u]};
    head[u] = cnt;
}

int id[maxn][maxn];
int g[maxn][maxn];
int st, ed;
int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[8] = {-1, 1, -1, 1, 2, 2, -2, -2};
bool flags[maxn][maxn];
void dfs(int p, int x, int y)
{
    flags[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 1 || newy < 1 || newx > n || newy > m || flags[newx][newy] || g[newx][newy] == 2)
            continue;
        if (g[newx][newy] == 1)
            dfs(p, newx, newy);
        else
        {
            flags[newx][newy] = 1;
            addEdge(p, id[newx][newy], 1);
        }
    }
}

void init()
{
    read(n, m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            read(g[i][j]);
            id[i][j] = m * (i - 1) + j;
            if (g[i][j] == 3)
                st = id[i][j];
            else if (g[i][j] == 4)
                ed = id[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == 0 || g[i][j] == 3)
            {
                memset(flags, false, sizeof(flags));
                dfs(id[i][j], i, j);
            }
        }
    }
}
int dis[maxn * maxn];
bool vis[maxn * maxn];
ll ans[maxn * maxn];
void dijkstra(int s)
{
    priority_queue<pair<int, int>> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    q.push({0, s});
    ans[s] = 1;
    while (!q.empty())
    {
        auto out = q.top();
        q.pop();
        int u = out.second;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (dis[v] > dis[u] + edge[i].w)
            {
                dis[v] = dis[u] + edge[i].w;
                ans[v] = ans[u];
                q.push({-dis[v], v});
            }
            else if (dis[v] == dis[u] + 1)
            {
                ans[v] = ans[v] + ans[u];
            }
        }
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    init();
    dijkstra(st);
    if (dis[ed] == INF)
        printf("-1\n");
    else
        printf("%d\n%lld\n", dis[ed] - 1, ans[ed]);
    return 0;
}