#include <iostream>
#include <map>
#include <stdio.h>
#include <queue>
#define ll long long
namespace FAST_IO
{
    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = nextChar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = nextChar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = nextChar();
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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
struct Node
{
    int mp[6][6];
    int step;
    bool operator<(const Node &a) const
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (mp[i][j] != a.mp[i][j])
                    return mp[i][j] < a.mp[i][j];
            }
        }
        return mp[0][0] < a.mp[0][0];
    }
} now;
map<Node, bool> vis;
queue<Node> q;
void bfs()
{
    q.push(now);
    vis[now] = true;
    while (!q.empty())
    {
        auto out = q.front();
        q.pop();
        if (out.mp[2][5] == 1)
        {
            int cnt = 1;
            for (int i = 4; i >= 0; i--)
            {
                if (out.mp[2][i] != 1)
                    break;
                cnt++;
            }
            int ans = out.step + cnt;
            printf("%d\n", ans > 10 ? -1 : ans);
            return;
        }
        if (out.step >= 10)
            break;

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (out.mp[i][j] == 0)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k], y = j + dy[k];
                        if (x < 0 || x >= 6 || y < 0 || y >= 6 || out.mp[x][y] == 0)
                            continue;
                        int xx = x + dx[k], yy = y + dy[k];
                        if (xx < 0 || xx >= 6 || yy < 0 || yy >= 6 || out.mp[xx][yy] != out.mp[x][y])
                            continue;
                        while (xx >= 0 && xx < 6 && yy >= 0 && yy < 6 && out.mp[xx][yy] == out.mp[x][y])
                        {
                            xx = xx + dx[k];
                            yy = yy + dy[k];
                        }
                        xx = xx - dx[k];
                        yy = yy - dy[k];
                        Node next = out;
                        next.step += 1;
                        swap(next.mp[i][j], next.mp[xx][yy]);
                        if (!vis.count(next))
                        {
                            q.push(next);
                            vis[next] = 1;
                        }
                    }
                }
            }
        }
    }
    printf("-1\n");
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> now.mp[i][j];
        }
    }
    now.step = 0;
    bfs();
    return 0;
}