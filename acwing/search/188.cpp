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
const int maxn = 150 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
char a[maxn][maxn];

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
struct Node
{
    int x, y;
    int dis;
};
queue<Node> q;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(m, n);
    // getchar();
    Node s, e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = getchar();
            if (a[i][j] == 'K')
            {
                s = {i, j, 0};
            }
            else if (a[i][j] == 'H')
            {
                e = {i, j, -1};
            }
        }
        getchar();
    }

    q.push(s);
    a[s.x][s.y] = '*';
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        if (u.x == e.x && u.y == e.y)
        {
            printf("%d\n", u.dis);
            break;
        }
        for (int i = 0; i < 8; i++)
        {
            int newx = u.x + dx[i];
            int newy = u.y + dy[i];
            if (newx < 0 || newx >= n || newy < 0 || newy >= m || a[newx][newy] == '*')
                continue;
            a[newx][newy] = '*';
            q.push({newx, newy, u.dis + 1});
        }
    }
    return 0;
}