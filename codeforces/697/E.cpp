#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
    {
        return read(x), read(y...);
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
int a[maxn];

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
ll ifac[maxn], fac[maxn];
void init(int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod; // 算出 n!
    ifac[n] = qpow(fac[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i--)
        ifac[i] = (i + 1) * ifac[i + 1] % mod;
}

ll nCm(int n, int m)
{
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    init(1000);
    while (tcase--)
    {
        read(n, k);
        for (int i = 1; i <= n; i++)
            a[i] = 0;
        for (int i = 1, x; i <= n; i++)
        {
            read(x);
            a[x]++;
        }
        int sum = 0;
        ll ans = 0;
        for (int i = n; i >= 1; i--)
        {
            if (a[i])
            {
                if (a[i] + sum >= k)
                {
                    ans = nCm(a[i], k - sum);
                    break;
                }
                else
                {
                    sum += a[i];
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}