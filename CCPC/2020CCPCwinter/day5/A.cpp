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
const double eqs = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int n, k, a[maxn][5], m, ans;
int cnt[4][4];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, k);
    int ans = 0;
    for (int i = 1, x; i <= k; i++)
    {
        read(x), a[i][0] = x;
        for (int j = 1, y; j <= x; j++)
        {
            read(y), a[y][i] = 1;
        }
    }
    if (k == 1)
    {
        printf("%d\n", a[k][0]);
    }
    else if (k == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i][1] && a[i][2])
                ans++;
            else if (a[i][1])
                cnt[1][1]++;
            else if (a[i][2])
                cnt[2][2]++;
        }
        printf("%d\n", ans + max(cnt[1][1], cnt[2][2]));
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i][1] && a[i][2] && a[i][3])
                ans++;
            else if (a[i][1] && a[i][2])
                cnt[1][2]++;
            else if (a[i][1] && a[i][3])
                cnt[1][3]++;
            else if (a[i][2] && a[i][3])
                cnt[2][3]++;
            else if (a[i][1])
                cnt[1][1]++;
            else if (a[i][2])
                cnt[2][2]++;
            else if (a[i][3])
                cnt[3][3]++;
        }
        cnt[3][3] -= min(cnt[3][3], cnt[1][2]);
        cnt[2][2] -= min(cnt[2][2], cnt[1][3]);
        cnt[1][1] -= min(cnt[1][1], cnt[2][3]);
        ans += max(cnt[1][1], max(cnt[2][2], cnt[3][3]));
        ans += cnt[1][2] + cnt[2][3] + cnt[1][3];
        printf("%d\n", ans);
    }
    return 0;
}