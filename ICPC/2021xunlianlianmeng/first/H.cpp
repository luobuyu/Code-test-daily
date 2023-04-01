#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = nextChar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = nextChar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = nextChar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
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

int head[maxn], cnt;
struct Edge
{
    int v, next;
    ll w;
} edge[maxm << 1];
inline void addEdge(int u, int v, ll w)
{
    ++cnt;
    edge[cnt] = {v, head[u], w};
    head[u] = cnt;
}

bool vis[maxn];
ll dis[maxn];
void dijstra(int s)
{
    priority_queue<pair<ll, int>> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));

    dis[s] = 0;
    q.push({-dis[s], s});
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
            if (dis[u] + edge[i].w < dis[v])
            {
                dis[v] = dis[u] + edge[i].w;
                q.push({-dis[v], v});
            }
        }
    }
}

void init()
{
    memset(head, 0, sizeof(head));
    cnt = 0;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, m);
    for (int i = 1, u, v; i <= m; i++)
    {
        read(u, v);
        addEdge(u, v, 1);
        addEdge(v, u, 1);
    }
    dijstra(1);
    printf("%lld\n", dis[n] - 1);
    return 0;
}