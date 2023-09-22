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
const int maxn = 2e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int matrix[maxn][maxn];
int lef[maxn][maxn];
int righ[maxn][maxn];
int heigh[maxn][maxn];
void solve()
{
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        lef[i][1] = 1;
        for (int j = 2; j <= m; ++j)
        {
            if (matrix[i][j] == !matrix[i][j - 1])
                lef[i][j] = lef[i][j - 1] + 1;
            else
                lef[i][j] = 1;
        }
        righ[i][m] = 1;
        for (int j = m - 1; j >= 1; --j)
        {
            if (matrix[i][j] == !matrix[i][j + 1])
                righ[i][j] = righ[i][j + 1] + 1;
            else
                righ[i][j] = 1;
        }
        for (int j = 1; j <= m; ++j)
        {
            heigh[i][j] = 1;
            if (i >= 2 && matrix[i][j] == !matrix[i - 1][j])
            {
                heigh[i][j] = heigh[i - 1][j] + 1;
                lef[i][j] = min(lef[i][j], lef[i - 1][j]);
                righ[i][j] = min(righ[i][j], righ[i - 1][j]);
            }
            int w = righ[i][j] + lef[i][j] - 1;
            int h = heigh[i][j];
            ans1 = max(ans1, min(w, h) * min(w, h));
            ans2 = max(ans2, w * h);
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    read(n, m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            read(matrix[i][j]);
        }
    }
    solve();
    return 0;
}