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
const int maxm = 2e4 + 10;
int t, n, m, k;
struct Node
{
    int v, w, s;
};
Node a[maxn];
int dp[maxn][maxm];
int q[maxm];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    read(n, m);
    for (int i = 1, v, w, s; i <= n; ++i)
    {
        read(a[i].v, a[i].w, a[i].s);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        // 枚举余数
        for (int r = 0; r < a[i].v; ++r)
        {
            int hh = 0, tt = -1;
            // 单调减队列
            for (int j = r; j <= m; j += a[i].v)
            {
                // 如果队列长度大于了 s，弹出队首
                while (hh <= tt && j - q[hh] > a[i].s * a[i].v)
                    hh++;
                while (hh <= tt && dp[i - 1][q[tt]] + (j - q[tt]) / a[i].v * a[i].w <= dp[i - 1][j])
                    --tt;
                q[++tt] = j;
                // 计算需要加多少倍的 w
                dp[i][j] = dp[i - 1][q[hh]] + (j - q[hh]) / a[i].v * a[i].w;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}