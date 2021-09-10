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
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e2 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
char a[maxn][maxn];
bool vis[maxn][maxn];
int sx, sy, ex, ey;
bool ans;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool dfs(int x, int y)
{
    if (a[x][y] == '#')
        return false;
    if (x == ex && y == ey)
        return true;

    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx >= n || newy < 0 || newy >= n || vis[newx][newy] == 1)
            continue;
        if (dfs(newx, newy))
            return true;
    }
    return false;
}

/**
 * 这个题目坑比较多，因为传入的起点终点可能是同一个点，
 * 而且传入的起点终点可能是 #，所以直接返回 false
 * **/
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);

    while (tcase--)
    {
        read(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = getchar();
            }
            getchar();
        }
        memset(vis, 0, sizeof(vis));
        read(sx, sy, ex, ey);
        if (a[sx][sy] == '#' || a[ex][ey] == '#')
            ans = false;
        else if (sx == ex && sy == ey)
        {
            ans = true;
        }
        else
        {
            ans = dfs(sx, sy);
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}