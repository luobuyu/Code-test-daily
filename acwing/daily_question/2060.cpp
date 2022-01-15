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
const int maxm = 1e2 + 10;
int t, n, m, k;
char g[maxn][maxn];
vector<pair<int, int>> a, b;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void bfs(int x, int y, int flag)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    g[x][y] = '.';
    while (!q.empty())
    {
        auto out = q.front();
        q.pop();
        if (flag)
        {
            b.push_back(out);
        }
        else
        {
            a.push_back(out);
        }
        for (int i = 0; i < 4; i++)
        {
            int newx = dx[i] + out.first;
            int newy = dy[i] + out.second;
            if (newx < 0 || newx >= n || newy < 0 || newy >= m || g[newx][newy] == '.')
                continue;
            q.push({newx, newy});
            g[newx][newy] = '.';
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
        scanf("%s", g[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'X')
            {
                if (cnt)
                {
                    bfs(i, j, cnt);
                }
                else
                {
                    bfs(i, j, cnt);
                }
                cnt++;
            }
        }
    }
    int ans = INF;
    for (auto x : a)
    {
        for (auto y : b)
        {
            ans = min(ans, abs(x.first - y.first) + abs(x.second - y.second) - 1);
        }
    }
    cout << ans << endl;
    return 0;
}