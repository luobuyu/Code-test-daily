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
const int maxn = 1e2 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int g[maxn][maxn];
int color[maxn];
int ans, cnt;

bool check(int u, int col)
{
    for (int i = 1; i <= n; i++)
    {
        if (g[u][i] && color[i] == col)
            return false;
    }
    return true;
}

void dfs(int step, int fa)
{
    if (step == n + 1)
    {
        if (ans != -1)
            ans = min(ans, cnt);
        else
            ans = cnt;
        return;
    }
    else
    {
        for (int i = 1; i <= cnt; i++)
        {
            if (check(step, i))
            {
                color[step] = i;
                dfs(step + 1, i);
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
    for (int i = 1, u, v; i <= m; i++)
    {
        read(u, v);
        g[u][v] = g[v][u] = 1;
    }
    cnt = 1;
    ans = -1;
    while (ans == -1)
    {
        for (int i = 1; i <= n; i++)
        {
            color[i] = 0;
        }
        dfs(1, 0);
        cnt++;
    }
    printf("%d\n", ans - 1);

    return 0;
}