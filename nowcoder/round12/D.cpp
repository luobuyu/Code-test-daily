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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
ll a[maxn];
ll sum[maxn][32][2];
ll dp[maxn];
void count(int i, int num)
{
    for (int j = 31; j >= 0; --j)
    {
        if ((num >> j) & 1)
            sum[i][j][1] = 1 * i;
        else
            sum[i][j][0] = 1 * i;
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    read(n);
    for (int i = 1; i <= n; ++i)
    {
        read(a[i]);
        count(i, a[i]);
        for (int j = 0; j < 32; ++j)
        {
            sum[i][j][0] += sum[i - 1][j][0];
            sum[i][j][1] += sum[i - 1][j][1];
        }
    }
    ll ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        ll tmp = 0;
        for (int j = 31; j >= 0; --j)
        {
            if ((a[i] >> j) & 1)
            {
                // 找0的个数
                int cnt0 = sum[i - 1][j][0];
                tmp = (tmp + 1ll * cnt0 * (1 << j)) % mod;
            }
            else
            {
                // 找 1 的个数
                int cnt1 = sum[i - 1][j][1];
                tmp = (tmp + 1ll * cnt1 * (1 << j)) % mod;
            }
        }
        dp[i] = (dp[i - 1] + tmp) % mod;
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << endl;
    return 0;
}