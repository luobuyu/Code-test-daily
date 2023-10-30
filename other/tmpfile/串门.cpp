// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
struct Edge
{
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};
vector<Edge> g[maxn];
ll ans_u = 1, dis_u = 0;
void dfs(int u, int fa, ll dis)
{
    if (dis > dis_u)
    {
        ans_u = u;
        dis_u = dis;
    }
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i].v, w = g[u][i].w;
        if (v == fa)
            continue;
        dfs(v, u, dis + w);
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    read(n);
    int u, v, w;
    ll sum = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        read(u, v, w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        sum += w;
    }
    sum *= 2;
    dfs(1, 0, 0);
    dis_u = 0;
    dfs(ans_u, -1, 0);
    cout << sum - dis_u << endl;
    return 0;
}