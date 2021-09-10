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
const int maxn = 3e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m1, m2, k;

int head[maxn], cnt;
struct Edge
{
    int u, v, w, next;
} edge[maxm << 1];
void addEdge(int u, int v, int w)
{
    edge[++cnt] = {u, v, w, head[u]};
    head[u] = cnt;
}

struct Node
{
    int l, r, k;
} a[maxn], b[maxn];
int dis[maxn];
bool vis[maxn];
int times[maxn];

void buildG(int mid)
{
    for (int i = 0; i <= n; i++)
    {
        head[i] = -1;
    }
    cnt = 0;

    for (int i = 1; i <= m1; i++)
    {
        addEdge(a[i].r, a[i].l - 1, -a[i].k);
    }
    for (int i = 1; i <= m2; i++)
    {
        addEdge(b[i].l - 1, b[i].r, mid - b[i].k);
    }
    for (int i = 1; i <= n; i++)
    {
        addEdge(i, i - 1, 0);
        addEdge(i - 1, i, 1);
    }
    addEdge(n, 0, -mid), addEdge(0, n, mid);
}

// 优化思路：将原队列改成双端队列，对要加入队列的点 p，
// 如果 dist[p] 小于队头元素 u 的 dist[u]，将其插入到队头，否则插入到队尾。
bool spfa_slf(int s, int n)
{
    for (int i = 0; i <= n; i++)
    {
        dis[i] = INF;
        times[i] = 0;
        vis[i] = false;
    }
    deque<int> deq;
    deq.push_back(s);
    times[s] = 1;
    dis[s] = 0;
    vis[s] = 1;
    while (!deq.empty())
    {
        int u = deq.front();
        deq.pop_front();
        vis[u] = 0;
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v, w = edge[i].w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (dis[v] < 0)
                    return false;
                if (vis[v])
                    continue;
                times[v]++, vis[v] = 1;
                if (times[v] > n)
                    return false;
                if (!deq.empty() && dis[v] < dis[deq.front()])
                    deq.push_front(v);
                else
                    deq.push_back(v);
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
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n, m1, m2);
        for (int i = 1; i <= m1; i++)
        {
            read(a[i].l, a[i].r, a[i].k);
        }
        for (int i = 1; i <= m2; i++)
        {
            read(b[i].l, b[i].r, b[i].k);
        }
        int l = 0, r = n, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            buildG(mid);
            if (spfa_slf(0, n + 1))
            {
                r = mid - 1;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}