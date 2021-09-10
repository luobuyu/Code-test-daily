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
const int maxn = 3e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

int fa[maxn];
int cntEdge[maxn], cntV[maxn];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        cntV[i] = 1;
        cntEdge[i] = 0;
    }
}

int findFa(int u)
{
    if (fa[u] == u)
    {
        return u;
    }
    return fa[u] = findFa(fa[u]);
}

void unite(int u, int v)
{
    int up = findFa(u);
    int vp = findFa(v);
    if (up != vp)
    {
        fa[up] = vp;
        cntV[vp] += cntV[up];
        cntEdge[vp] += cntEdge[up] + 1;
    }
    else
    {
        cntEdge[up]++;
    }
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    for (int caseid = 1; caseid <= tcase; caseid++)
    {
        int ans = 0;
        read(n, m);
        init(n + 5);
        for (int i = 1, u, v; i <= m; i++)
        {
            read(u, v);
            unite(u, v);
        }

        for (int i = 1; i <= n; i++)
        {
            if (findFa(i) == i)
            {
                if (cntEdge[i] - cntV[i] > 0)
                {
                    ans += cntEdge[i] - cntV[i];
                }
            }
        }
        printf("Case #%d: %d\n", caseid, ans);
    }
    return 0;
}