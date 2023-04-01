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
const int maxm = 2e7 + 10;
int t, n, m, k;
char s[maxn][maxn];
int dx[9] = {0, 0, 0, 1, -1, -1, -1, 1, 1};
int dy[9] = {0, 1, -1, 0, 0, -1, 1, -1, 1};
struct Node
{
    int x, y, vx, vy, k, d;
    bool check()
    {
        if (x < 1 || y < 1 || x > n || y > m || s[x][y] == '#')
            return 0;
        if (abs(vx) > 7 || abs(vy) > 7)
            return 0;
        return 1;
    }
    int hash() { return x + y * 50 + (vx + 8) * 50 * 50 + (vy + 8) * 50 * 50 * 15 + (k + 1) * 50 * 50 * 15 * 15; }
};
queue<Node> q;
bool mp[maxm];

bool bfs()
{
    while (!q.empty())
    {
        auto out = q.front();
        q.pop();
        for (int i = 0; i < 9; i++)
        {
            auto newp = out;
            newp.vx += dx[i];
            newp.vy += dy[i];
            newp.x += newp.vx;
            newp.y += newp.vy;
            newp.d++;
            if (!newp.check())
                continue;
            if (newp.k == s[newp.x][newp.y] - '0')
                newp.k++;
            if (newp.k == k + 2 && s[newp.x][newp.y] - '0' == k + 1 && newp.vx == 0 && newp.vy == 0)
            {
                printf("%d\n", newp.d);
                return true;
            }
            // cout << newp.hash() << endl;
            if (mp[newp.hash()])
                continue;
            q.push(newp);
            mp[newp.hash()] = 1;
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
    read(n, m, k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == '0')
            {
                q.push({i, j, 0, 0, 1, 0});
                mp[q.front().hash()] = 1;
            }
        }
    }
    if (!bfs())
    {
        printf("impossible\n");
    }
    return 0;
}