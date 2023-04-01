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
const int maxn = 5e3 + 10;
const int maxm = 5e3 + 10;
int t, n, m, k;

int head[maxn], cnt;
struct Edge
{
    int u, v, w, next;
} edge[maxm << 1];
inline void addEdge(int u, int v, int w)
{
    edge[++cnt] = {u, v, w, head[u]};
    head[u] = cnt;
}

int dis[maxn];
bool vis[maxn];
int times[maxn];
bool spfa(int s)
{
    queue<int> q;
    memset(vis, false, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0, vis[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int out = q.front();
        q.pop();
        vis[out] = false;
        for (int i = head[out]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (dis[v] > dis[out] + edge[i].w)
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
    for (int i = 1, u, v, w; i <= m; i++)
    {
        read(v, u, w);
        addEdge(u, v, w);
    }
    for (int i = 1; i <= n; i++)
        addEdge(0, i, 0);
    if (!spfa(0))
        printf("NO\n");
    else
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", dis[i], " \n"[i == n]);
        }
    }

    return 0;
}