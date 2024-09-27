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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
char a[maxn][maxn];
int x, y;
void put2x2(int startx, int starty)
{
    if (x == 0)
        return;
    // 检查上侧和左侧
    vector<bool> flag(4);
    if (startx - 1 >= 0)
    {
        flag[a[startx - 1][starty] - 'a'] = true;
    }
    if (starty - 1 >= 0)
    {
        flag[a[startx][starty - 1] - 'a'] = true;
    }
    char ch = 'a';
    for (int i = 0; i < 4; ++i)
    {
        if (!flag[i])
        {
            ch += i;
            break;
        }
    }
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            a[startx + i][starty + j] = ch;
        }
    }
    x--;
    if (starty + 2 >= m)
    {
        startx += 2;
        starty = 0;
    }
    else
    {
        starty += 2;
    }
    put2x2(startx, starty);
}

void put1x1(int startx, int starty)
{
    if (y == 0)
        return;
    vector<bool> flag(4);
    if (a[startx][starty] == '\0')
    {
        // 检查上侧和左侧
        if (startx - 1 >= 0)
        {
            flag[a[startx - 1][starty] - 'a'] = true;
        }
        if (starty - 1 >= 0)
        {
            flag[a[startx][starty - 1] - 'a'] = true;
        }
        char ch = 'a';
        for (int i = 0; i < 4; ++i)
        {
            if (!flag[i])
            {
                ch += i;
                break;
            }
        }
        a[startx][starty] = ch;
        --y;
    }
    starty++;
    if (starty >= m)
    {
        startx++;
        starty = 0;
    }
    put1x1(startx, starty);
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x >> y;
    put2x2(0, 0);
    put1x1(0, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}