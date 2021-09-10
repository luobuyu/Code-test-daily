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
    inline void read(T &x, _T &... y)
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
const int maxm = 1e5 + 10;
int t, n, m, k;

struct Node
{
    int u, v, w;
    bool operator<(Node &x) const
    {
        return w < x.w;
    }
};

vector<Node> g[maxn];

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    int m = n * (n - 1) / 2;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        read(u, v, w);
        g[u].push_back({u, v, w});
        g[v].push_back({v, u, w});
    }
    for (int i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < g[i].size() / 2; j++)
        {
            ans += max(g[i][j * 2].w, g[i][j * 2 + 1].w);
        }
    }
    printf("%lld\n", ans);
    return 0;
}