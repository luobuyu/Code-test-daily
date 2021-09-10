#include <bits/stdc++.h>
#define ll long long
#define lll __int128
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
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;


int getId(int y, int m, int d)
{
    if(m < 3) y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * (m - 3) + 2) / 5 + d - 307;
}
int a[maxn][maxn];
int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, 1, 0, -1};

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    getchar();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char ch;
            ch = getchar();
            if(ch == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
        getchar();
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 1)
            {
                bool flag = true;
                for(int k = 1; k <= 4; k++)
                {
                    int newx = i + dx[k];
                    int newy = j + dy[k];
                    if(newx >= 1 && newx <= n && newy >= 1 && newy <= n)
                    {
                        if(a[newx][newy] == 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}