#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = nextChar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = nextChar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = nextChar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 999101;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e6 + 10;
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
    return ans % mod;
}

ll fac[maxn], ifac[maxn];
void init(int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    ifac[n] = qpow(fac[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i--)
    {
        ifac[i] = (i + 1) * ifac[i + 1] % mod;
    }
}

ll nCm(int n, int m)
{
    return fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, m, k);
    init(n);
    if (n >= 1e7)
    {
        printf("0\n");
    }
    else
    {
        ll ans = 0;
        for (int i = 0; i <= n; i++)
        {
            ans = (ans + nCm(n, i) * qpow(i, k, mod) % mod) % mod;
        }
        ans = ans * nCm(n, m) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}