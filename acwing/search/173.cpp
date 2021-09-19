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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int g[maxn][maxn];
int b[maxn][maxn];
char s[maxn];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool vis[maxn][maxn];
queue<pair<int, int>> q;
void bfs()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 1)
            {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    while (q.size())
    {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = u.first + dx[i];
            int y = u.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y])
                continue;
            b[x][y] = b[u.first][u.second] + 1;
            q.push({x, y});
            vis[x][y] = true;
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
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        for (int j = 0; j < m; j++)
        {
            g[i][j] = s[j] - '0';
        }
    }
    bfs();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d%c", b[i][j], " \n"[j == m - 1]);
        }
    }
    return 0;
}