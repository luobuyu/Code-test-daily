#include <bits/stdc++.h>
#define ll long long
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

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

struct Node
{
    int u, v, w;
} edge[maxm];
int fa[maxn];
int getFa(int u)
{
    return fa[u] == u ? u : fa[u] = getFa(fa[u]);
}

bool cmp(Node &a, Node &b)
{
    return a.w > b.w;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, m);
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        Node &a = edge[i];
        cin >> a.u >> a.v >> a.w;
    }
    sort(edge + 1, edge + 1 + m, cmp);
    int cnt = 1;
    int ans = 0;
    int pre = -1;
    for (int i = 1; i <= m; i++)
    {
        int u = edge[i].u, v = edge[i].v;
        int up = getFa(u), vp = getFa(v);
        if (up != vp)
        {
            fa[up] = vp;
            if (pre != edge[i].w)
            {
                ans++;
                pre = edge[i].w;
            }
        }
    }
    cout << ans << endl;
    return 0;
}