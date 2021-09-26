#include <bits/stdc++.h>
#define ll long long
#define lll long long
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 2e5 + 10;
int t, n, m, k;
int s, e;

struct Edge
{
    int u, v, w, next;
} edge[maxm];
int head[maxn], rhead[maxn], cnt = 0;

inline void addEdge(int u, int v, int w)
{
    edge[++cnt] = {u, v, w, head[u]};
    head[u] = cnt;
    edge[++cnt] = {v, u, w, rhead[v]};
    rhead[v] = cnt;
}
int h[maxn];
struct Node
{
    int u;
    int dis;
    bool operator<(const Node &p) const
    {
        return dis < p.dis;
    }
};

bool vis[maxn];
void dijkstra(int s)
{
    priority_queue<Node> q;
    memset(h, 0x3f, sizeof(h));
    memset(vis, false, sizeof(vis));
    h[s] = 0;
    q.push({s, 0});
    while (q.size())
    {
        auto out = q.top();
        q.pop();

        int u = out.u;
        if (vis[u])
            continue;
        vis[u] = true;

        for (int i = rhead[u]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (h[v] > h[u] + edge[i].w)
            {
                h[v] = h[u] + edge[i].w;
                q.push({v, -h[v]});
            }
        }
    }
}
// A星 优先级队列里面放 f(x)
// g
int times[maxn];
int astar()
{
    priority_queue<Node> q;
    q.push({s, -h[s]});
    while (q.size())
    {
        auto out = q.top();
        q.pop();
        int u = out.u;
        int gdis = -out.dis - h[u];
        times[u]++;
        if (times[e] == k)
        {
            return gdis;
        }
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (times[v] < k)
            {
                q.push({v, -(gdis + edge[i].w + h[v])});
            }
        }
    }
    return -1;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, m);
    for (int i = 1, u, v, w; i <= m; i++)
    {
        read(u, v, w);
        addEdge(u, v, w);
    }
    read(s, e, k);
    if (s == e)
        k++;
    dijkstra(e);
    // cout << h[s] << endl;
    int ret = astar();
    cout << ret << endl;
    return 0;
}
