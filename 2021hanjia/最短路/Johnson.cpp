#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 3e3 + 10;
const int maxm = 1e4 + 10;
int t, n, m, k;

int head[maxn], cnt;
struct Edge
{
    int u, v, w, next;
} edge[maxm];
inline void addEdge(int u, int v, int w)
{
    edge[++cnt] = {u, v, w, head[u]};
    head[u] = cnt;
}

ll h[maxn], dis[maxn];
bool vis[maxn];
int times[maxn];
bool spfa(int s)
{
    queue<int> q;
    memset(h, 0x3f, sizeof(h));
    memset(vis, false, sizeof(vis));
    h[s] = 0;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (h[v] > h[u] + edge[i].w)
            {
                h[v] = h[u] + edge[i].w;
                if (vis[v])
                    continue;
                q.push(v);
                vis[v] = true;
                if (++times[v] > n)
                    return false;
            }
        }
    }
    return true;
}

void dijkstra(int s)
{
    priority_queue<pair<int, int>> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    q.push({0, s});
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
                if (!vis[v])
                    q.push({-dis[v], v});
            }
        }
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n, m);
    for (int i = 1, u, v, w; i <= m; i++)
    {
        read(u, v, w);
        addEdge(u, v, w);
    }
    for (int i = 1; i <= n; i++)
    {
        addEdge(0, i, 0);
    }
    if (!spfa(0))
    {
        printf("-1\n");
    }
    else
    {
        for (int u = 1; u <= n; u++)
        {
            for (int i = head[u]; i; i = edge[i].next)
            {
                int u = edge[i].u, v = edge[i].v;
                edge[i].w += h[u] - h[v];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            dijkstra(i);
            ll ans = 0;
            for (ll j = 1; j <= n; j++)
            {
                if (dis[j] == INF_LL)
                    ans += j * 1e9;
                else
                    ans += j * (dis[j] + h[j] - h[i]);
            }
            cout << ans << endl;
        }
    }

    return 0;
}