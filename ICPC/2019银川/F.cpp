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
const ll mod = 998244353;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-7;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
ll t, n, m, k;
ll qpow(ll a, ll b, ll mod)
{
    ll ans = 1, tmp = a;
    while (b)
    {
        if (b & 1)
            ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    ll sum = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        long double cc = log((long double)n) / log((long double)i);
        ll c = cc;
        ll tmp = 0;
        for (int j = 1; j < c; j++)
        {
            tmp = (tmp + qpow(i, j, mod) * j % mod * (i - 1) % mod) % mod;
        }
        tmp = (tmp + ((n - qpow(i, c, mod) + 1) % mod + mod) % mod * (c) % mod) % mod;
        sum = (sum + i * tmp % mod) % mod;
    }
    //printf("%lld\n", sum);
    ll tmp = sqrt(n) + 1;

    n %= mod;
    ll a1 = (n - tmp + 1 + mod) % mod * (n + tmp) % mod * qpow(2, mod - 2, mod) % mod;
    ll a2 = n * (n + 1) % mod * ((2 * n % mod + 1) % mod) % mod * qpow(6, mod - 2, mod) % mod;
    a2 = (a2 - (tmp - 1) * tmp % mod * ((2 * (tmp - 1) % mod + 1) % mod) % mod * qpow(6, mod - 2, mod) % mod + mod) % mod;
    ll ans = ((n + 1) * a1 % mod - a2 + mod) % mod;
    ans = (ans + sum) % mod;
    printf("%lld\n", ans);
    return 0;
}