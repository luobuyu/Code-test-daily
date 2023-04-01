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
const int maxn = 1e3 + 10;
const int maxm = 3e5 + 10;
int t, n, m, k;
int head[maxn], cnt;
struct Edge
{
    int u, v, next;
} edge[maxm];

inline void addEdge(int u, int v)
{
    edge[++cnt] = {u, v, head[u]};
    head[u] = cnt;
}
double a[maxn][maxn];
double f[maxn], g[maxm];
int deg[maxn];

void gauss(int n)
{
    double div;
    for (int i = 1; i <= n; i++)
    {
        int maxx = i;
        for (int j = i + 1; j <= n; j++)
        {
            if (fabs(a[j][i]) > fabs(a[maxx][i]))
            {
                maxx = j;
            }
        }
        for (int j = 1; j <= n + 1; j++)
        {
            swap(a[i][j], a[maxx][j]);
        }
        div = a[i][i];
        for (int j = i; j <= n + 1; j++)
        {
            a[i][j] /= div;
        }

        for (int k = 1; k <= n; k++)
        {
            if (k != i)
            {
                div = a[k][i];
                for (int j = i; j <= n + 1; j++)
                {
                    a[k][j] -= div * a[i][j];
                }
            }
        }
    }
}

bool cmp(double a, double b)
{
    return a > b;
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
        addEdge(u, v), addEdge(v, u);
        ++deg[u], ++deg[v];
    }
    a[1][n] = 1;
    for (int u = 1; u < n; u++)
    {
        a[u][u] = 1;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (v != n)
            {
                a[u][v] -= 1.0 / deg[v];
            }
        }
    }
    gauss(n - 1);
    for (int i = 1; i <= cnt; i += 2)
    {
        int u = edge[i].u, v = edge[i].v;
        g[(i - 1) / 2 + 1] = a[u][n] / deg[u] + a[v][n] / deg[v];
    }

    sort(g + 1, g + m + 1, cmp);
    double ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += g[i] * i;
    }
    printf("%.3f\n", ans);
    return 0;
}