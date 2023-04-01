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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

int head[maxn], cnt = 0;
struct Edge
{
    int u, v, w, next;
} edge[maxm << 2];
inline void addEdge(int u, int v, int w)
{
    edge[++cnt] = {u, v, w, head[u]};
    head[u] = cnt;
}

ll dis[maxn];
bool vis[maxn];
int times[maxn];
bool spfa(int s)
{
    queue<int> q;
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    dis[s] = 1, vis[s] = true;
    times[s]++;
    q.push(s);
    while (!q.empty())
    {
        int out = q.front();
        q.pop();
        vis[out] = false;
        for (int i = head[out]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (dis[v] < dis[out] + edge[i].w)
            {
                dis[v] = dis[out] + edge[i].w;
                if (vis[v])
                    continue;
                if (++times[v] >= n + 1)
                    return false;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return true;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int s;
    read(n, m);
    for (int i = 1, x, u, v; i <= m; i++)
    {
        read(x, u, v);
        if (x % 2 == 0 && u == v)
        {
            printf("-1\n");
            return 0;
        }
        if (x == 1)
        {
            addEdge(u, v, 0);
            addEdge(v, u, 0);
        }
        else if (x == 2)
        {
            addEdge(u, v, 1);
        }
        else if (x == 3)
        {
            addEdge(v, u, 0);
        }
        else if (x == 4)
        {
            addEdge(v, u, 1);
        }
        else if (x == 5)
        {
            addEdge(u, v, 0);
        }
    }
    for (int i = 1; i <= n; i++)
        addEdge(0, i, 0);
    if (!spfa(0))
        printf("-1\n");
    else
    {
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += dis[i];
        }
        printf("%lld\n", ans);
    }

    return 0;
}