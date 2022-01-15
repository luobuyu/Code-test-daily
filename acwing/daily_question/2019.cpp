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
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int sx, sy;
bool vis[maxn][maxn];
int dis[maxn][maxn];
int bfs()
{
    memset(dis, 0x3f, sizeof(dis));
    deque<pair<int, int>> q;
    q.push_back({sx, sy});
    dis[sx][sy] = 0;
    while (!q.empty())
    {
        auto out = q.front();
        q.pop_front();
        if (vis[out.first][out.second])
            continue;
        vis[out.first][out.second] = true;
        if (out.first == 0 && out.second == 0)
            break;
        for (int i = 0; i < 4; i++)
        {
            int newx = out.first + dx[i];
            int newy = out.second + dy[i];
            if (newx < 0 || newx > 1001 || newy < 0 || newy > 1001)
                continue;
            int w = 0;
            if (g[newx][newy])
                w = 1;
            if (dis[newx][newy] > dis[out.first][out.second] + w)
            {
                dis[newx][newy] = dis[out.first][out.second] + w;
                if (w)
                    q.push_back({newx, newy});
                else
                    q.push_front({newx, newy});
            }
        }
    }
    return dis[0][0];
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, sx, sy);
    int x, y;
    while (n--)
    {
        read(x, y);
        g[x][y] = 1;
    }
    cout << bfs() << endl;

    return 0;
}