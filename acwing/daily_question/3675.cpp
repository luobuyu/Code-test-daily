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
const int maxn = 1e2 + 10;
const int maxm = 1e5 + 10;
int n, m, k, t;
char a[maxn][maxn];
int sx, sy, ex, ey;
struct Node
{
    int x, y, z;
    int dis;
    bool operator<(const Node &rhs) const
    {
        return dis > rhs.dis;
    }
};
priority_queue<Node> q;
int dis[maxn][maxn][4];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool flag[maxn][maxn][4];
bool solve()
{
    while (q.size())
        q.pop();
    memset(dis, 0x3f, sizeof(dis));
    memset(flag, false, sizeof(flag));
    for (int i = 0; i < 4; i++)
    {
        q.push({sx, sy, i, 0});
        dis[sx][sy][i] = 0;
    }

    while (q.size())
    {
        auto out = q.top();
        q.pop();
        if (flag[out.x][out.y][out.z])
            continue;
        flag[out.x][out.y][out.z] = true;
        if (dis[out.x][out.y][out.z] > k)
            continue;
        if (out.x == ex && out.y == ey)
            return true;
        for (int i = 0; i < 4; i++)
        {
            int newx = out.x + dx[i], newy = out.y + dy[i];
            if (newx < 0 || newx >= n || newy < 0 || newy >= m || a[newx][newy] == '*')
                continue;
            int w = (i != out.z);
            if (dis[out.x][out.y][out.z] + w < dis[newx][newy][i])
            {
                dis[newx][newy][i] = dis[out.x][out.y][out.z] + w;
                q.push({newx, newy, i, dis[newx][newy][i]});
            }
        }
    }
    return false;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> k >> sy >> sx >> ey >> ex;
        sx--, sy--, ex--, ey--;

        cout << (solve() ? "yes" : "no") << endl;
    }
    return 0;
}
