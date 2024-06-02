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

ll qpow(ll a, ll b)
{
    ll ret = 1, tmp = a;
    while (b)
    {
        if (b & 1)
            ret = ret * tmp % mod;
        tmp = tmp * tmp % mod;
        b >>= 1;
    }
    return ret;
}

void test()
{
    int ans = 0;
    for (int i = 0; i <= 2; ++i)
    {
        for (int j = 0; j <= 2; ++j)
        {
            for (int k = 0; k <= 2; ++k)
            {
                if (i == j || j == k)
                    continue;
                ans += abs(i - j) + abs(k - j);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // dp[i][0] = dp[i - 1][1] + dp[i - 1][2]
    // dp[i][1] = dp[i - 1][0] + dp[i - 1][2]
    // dp[i][2] = dp[i - 1][0] + dp[i - 1][1]
    // dp[i] = dp[i - 1][1] + 4 + dp[i - 1][2] + 2 * 4 + dp[i - 1][0] + 1 + dp[i - 1][2] + 1 + dp[i - 1][0] + 2 + dp[i - 1][1] + 1;
    // dp[i] = dp[i - 1][1] * 2 + dp[i - 1][0] * 2 + dp[i - 1][2] * 2 + 8;
    // dp[n] = dp[2] * 2^(n - 2) + 8^(n - 2);
    // dp[i] = dp[i - 1] * 2 + 8;
    // dp[i + 1] = dp[i] * 2 + 8;
    // dp[i + 1] = (dp[i - 1] * 2 + 8) * 2 + 8;
    // dp[i + 1] = dp[i - 1] * 2 ^ 2 + 8 * 2 + 8;
    // dp[3] =
    // 8, 8 * 2, 8 * 4, 8 * 2^
    //
    // 8(2^(n - 1) - 1)/
    // 8 * 2 + 8

    test();
    cin >> n;
    if (n == 2)
    {
        cout << 8 << endl;
    }
    else
    {
        ll ans = (8 * qpow(2, n - 2) % mod + 8 * qpow(2, n - 1) - 1 + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}