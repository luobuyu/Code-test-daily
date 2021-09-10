#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 10;
const ll mod = 1e9 + 9;

ll read()
{
    ll x = 0, flag = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    }
    if (flag)
        return -x;
    return x;
}

ll t;
ll n, c, k;

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
int ifac[maxn], fac[maxn];
int aa[maxn], bb[maxn];
void init(int n)
{
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= n; i++)
        fac[i] = (ll)fac[i - 1] * i % mod; // 算出 n!
    ifac[n] = qpow(fac[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; --i)
        ifac[i] = (i + 1) * ifac[i + 1] % mod;
}

ll nCm(ll n, ll m)
{
    return ((fac[n] * ifac[m]) % mod * ifac[n - m]) % mod;
}

ll solve()
{
    ll ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ll tmpab = 0, tmp = 0;
        tmpab = aa[k - i] * bb[i] % mod;
        if (tmpab == 1)
            tmp = n % mod;
        else
            tmp = tmpab * (((qpow(tmpab, n, mod) - 1) % mod + mod) % mod) % mod * qpow(tmpab - 1, mod - 2, mod) % mod;
        if (i & 1)
            ans = (((ans - tmp * nCm(k, i) % mod) % mod) + mod) % mod;
        else
            ans = (ans + tmp * nCm(k, i) % mod) % mod;
    }
    ans = ans * qpow(276601605, k, mod) % mod;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif
    init(1e5 + 3);
    t = read();
    while (t--)
    {

        // n = read(), c = read(), k = read();
        // aa[0] = bb[0] = 1;
        // ll tmpa = qpow(691504013, c, mod);
        // ll tmpb = qpow(308495997, c, mod);
        // for (int i = 1; i <= k; i++)
        // {
        //     aa[i] = aa[i - 1] * tmpa % mod;
        //     bb[i] = bb[i - 1] * tmpb % mod;
        // }
        // printf("%lld\n", solve());
        int a, b;
        cin >> a;
        printf("%lld\n", qpow(a, mod - 2, mod));
    }
    return 0;
}