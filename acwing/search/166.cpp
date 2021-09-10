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
const int maxn = 1e1 + 10;
const int maxm = 1e5 + 10;
const int ROW = 0;
const int COL = 1;
const int GRID = 2;
int t, n, m, k;
char str[maxn * maxn];
int a[maxn][maxn];
int flag[3][9];
bool isfind;
bool vis[maxn][maxn];
void makeFlag(int row, int col, int x)
{
    x = 1 << (x - 1);
    int grid = row / 3 * 3 + col / 3;
    flag[ROW][row] ^= x;
    flag[COL][col] ^= x;
    flag[GRID][grid] ^= x;
    vis[row][col] ^= 1;
}

bool check(int x, int y, int p)
{
    int grid = x / 3 * 3 + y / 3;
    p = 1 << (p - 1);
    return !(flag[ROW][x] & p || flag[COL][y] & p || flag[GRID][grid] & p);
}
void dfs(int step, int x, int y)
{
    if (step == 81)
    {
        isfind = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d", a[i][j]);
            }
            // puts("");
        }
        puts("");
        return;
    }
    if (isfind)
        return;
    if(vis[x][y])
    {
        
    }
    for (int i = 1; i <= 9; i++)
    {
        if (check(x, y, i))
        {
            int tmp = a[x][y];
            a[x][y] = i;
            makeFlag(x, y, i);
            // cout << step << " " << x << " " << y << " " << a[x][y] << endl;
            dfs(step + 1, x + (y + 1) / 9, (y + 1) % 9);
            makeFlag(x, y, i);
            a[x][y] = tmp;
        }
    }
}

void init()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            flag[i][j] &= 0;
        }
    }
    isfind = false;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%s", str) && strcmp(str, "end") != 0)
    {
        for (int i = 0; i < 81; i++)
        {
            int row = i / 9, col = i % 9, grid = row * 3 + col;
            a[i / 9][i % 9] = (str[i] == '.' ? 0 : str[i] - '0');
            if (a[row][col])
                makeFlag(row, col, a[row][col]);
        }
        dfs(0, 0, 0);
    }

    return 0;
}