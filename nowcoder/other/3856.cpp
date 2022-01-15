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
const ll mod = 1e5;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e2 + 10;
int t, n, m, k;
int g[maxn][maxn];
bool flag[maxn][maxn];
int fa[maxn];

int getFa(int u)
{
    return fa[u] == u ? u : getFa(fa[u]);
}
struct Edge
{
    int u, v, w;
};
vector<Edge> edge;

ll qpow(ll a, ll b, ll mod)
{
    ll tmp = a, ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * tmp % mod;
        }
        tmp = tmp * tmp % mod;
        b >>= 1;
    }
    return ans;
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int dis[maxn];
bool vis[maxn];
void dfs(int u)
{
    vis[u] = true;
    for (int i = 0; i < n; i++)
    {
        if (flag[u][i])
        {
            if (vis[i])
                continue;
            dis[i] = (dis[u] + qpow(2, g[u][i], mod)) % mod;
            dfs(i);
        }
    }
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
            flag[i][j] = false;
        }
        fa[i] = i;
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[0] = 0;
    for (int i = 0, u, v; i < m; i++)
    {
        read(u, v);
        g[u][v] = g[v][u] = min(g[u][v], i);
        edge.push_back({u, v, i});
    }
    sort(edge.begin(), edge.end(), cmp);
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int uf = getFa(u), vf = getFa(v);
        if (uf == vf)
            continue;
        fa[uf] = vf;
        cnt++;
        flag[u][v] = flag[v][u] = true;
        if (cnt == n - 1)
            break;
    }
    dfs(0);
    for (int i = 1; i < n; i++)
    {
        if (dis[i] == INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", dis[i]);
        }
    }

    return 0;
}