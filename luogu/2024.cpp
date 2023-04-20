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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
struct UF
{
    vector<int> fa;
    UF(int n) : fa(n)
    {
        for (int i = 0; i < n; ++i)
            fa[i] = i;
    }
    int find(int u)
    {
        return u == fa[u] ? u : fa[u] = find(fa[u]);
    }
    void unite(int u, int v)
    {
        int up = find(u);
        int vp = find(v);
        if (up != vp)
            fa[up] = vp;
    }
    bool connect(int u, int v)
    {
        return find(u) == find(v);
    }
};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    read(n, k);
    UF uf(n * 3 + 10);
    int ans = 0;
    int op, a, b;
    // 同类，食物，天敌
    while (k--)
    {
        read(op, a, b);
        if (a > n || b > n)
        {
            ans++;
            continue;
        }
        if (op == 1)
        {
            if (uf.connect(a, b + n) || uf.connect(a, b + 2 * n))
            {
                ans++;
                continue;
            }
            uf.unite(a, b);
            uf.unite(a + n, b + n);
            uf.unite(a + 2 * n, b + 2 * n);
        }
        else
        {
            if (uf.connect(a, b + n) || uf.connect(a, b))
            {
                ans++;
                continue;
            }
            uf.unite(a + n, b);
            uf.unite(a, b + 2 * n);
            uf.unite(a + 2 * n, b + n);
        }
    }
    cout << ans << endl;
    return 0;
}