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
int a[maxn][maxn];
bool vis[maxn][maxn];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
struct Node
{
    int x, y;
};
queue<Node> q;
Node pre[maxn][maxn];
/**
 * 好久没写过路径问题了，需要记录每个点的pre，
 * 最好是使用和原图一样的数据结构记录
 * 
 * 
 **/
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            read(a[i][j]);
        }
    }
    int cnt = 0;
    int ans = 0;
    q.push({0, 0});
    pre[0][0] = {-1, -1};
    vis[0][0] = 1;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        if ((u.x == n - 1) && (u.y == n - 1))
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int newx = u.x + dx[i];
            int newy = u.y + dy[i];
            if (newx < 0 || newx >= n || newy < 0 || newy >= n || a[newx][newy] == 1 || vis[newx][newy] == 1)
                continue;
            vis[newx][newy] = 1;
            q.push({newx, newy});
            pre[newx][newy] = {u.x, u.y};
        }
    }
    stack<Node> s;
    int x = n - 1, y = n - 1;
    s.push({x, y});
    while (pre[x][y].x != -1 && pre[x][y].y != -1)
    {
        s.push(pre[x][y]);
        int tmpx = pre[x][y].x;
        int tmpy = pre[x][y].y;
        x = tmpx;
        y = tmpy;
    }

    while (!s.empty())
    {
        auto x = s.top();
        printf("%d %d\n", x.x, x.y);
        s.pop();
    }

    return 0;
}