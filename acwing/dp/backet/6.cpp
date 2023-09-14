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
int dp[maxm];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    read(n, m);
    for (int i = 0, v, w, s; i < n; ++i)
    {
        read(a[i].v, a[i].w, a[i].s);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
    {
        if (a[i].s * a[i].v >= m)
        {
            // 完全背包
            for (int j = a[i].v; j <= m; ++j)
            {
                dp[j] = max(dp[j], dp[j - a[i].v] + a[i].w);
            }
        }
        else
        {
            int k = 1;
            while (a[i].s != 0)
            {
                for (int j = m; j >= k * a[i].v; --j)
                {
                    dp[j] = max(dp[j], dp[j - k * a[i].v] + k * a[i].w);
                }
                a[i].s -= k;
                k <<= 1;S
                if (k > a[i].s)
                    k = a[i].s;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}