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
const double eps = 1e-9;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int head[maxn], cnt;
int deg[maxn];
struct Edge
{
    int v, w, next;
} edge[maxm];
inline void addEdge(int u, int v, int w)
{
    ++cnt;
    edge[cnt] = {v, w, head[u]};
    head[u] = cnt;
}

double a[maxn][maxn], ans;
inline int sgn(double x) { return x > eps ? 1 : x < -eps ? -1
                                                         : 0; }
void gauss()
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
        for (int j = i; j <= n + 1; j++)
        {
            swap(a[maxx][j], a[i][j]);
        }
        div = a[i][i];
        for (int j = i; j <= n + 1; j++)
        {
            a[i][j] /= div;
        }
        for (int j = 1; j <= n; j++)
        {
            if (j != i)
            {
                div = a[j][i];
                for (int k = i; k <= n + 1; k++)
                {
                    a[j][k] -= div * a[i][k];
                }
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
    read(n, m);
    for (int i = 1, u, v, w; i <= m; i++)
    {
        read(u, v, w);
        if (u == v)
        {
            ++deg[u];
            addEdge(u, v, w);
        }
        else
        {
            ++deg[u], ++deg[v];
            addEdge(u, v, w), addEdge(v, u, w);
        }
    }
    // 拆位
    for (int k = 1; k >= 0; k--)
    {
        memset(a, 0, sizeof(a));
        for (int i = 1; i < n; i++)
        {
            a[i][i] = deg[i];
            for (int p = head[i]; p; p = edge[p].next)
            {
                int v = edge[p].v, w = (edge[p].w >> k) & 1; // 二进制拆位后，该位

                if (w)
                    a[i][v] += 1, a[i][n + 1] += 1;
                else
                    a[i][v] -= 1;
            }
        }
        a[n][n] = 1;

        gauss();

        ans += (1 << k) * a[1][n + 1];
    }
    printf("%.3f\n", ans);
    return 0;
}