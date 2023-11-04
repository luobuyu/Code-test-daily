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
const int maxn = 2e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int fa[maxn], nex[maxn];
void init()
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        nex[i] = i + 1;
    }
}
int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
void unite(int u, int v)
{
    int up = find(u);
    int vp = find(v);
    if (up == vp)
        return;
    fa[up] = vp;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    read(n, q);
    int type, x, y;
    init();
    for (int i = 1; i <= q; ++i)
    {
        read(type, x, y);
        if (type == 1)
        {
            unite(x, y);
        }
        else if (type == 2)
        {
            // x, y
            int cur = x;
            int yp = find(y);
            while (cur <= y)
            {
                unite(cur, yp);
                int tmp = cur;
                cur = nex[cur];
                nex[tmp] = nex[y];
            }
        }
        else
        {
            cout << (find(x) == find(y) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}