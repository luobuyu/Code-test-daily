#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 5e6 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

ll ifac[maxn], fac[maxn];

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
ll cnt[maxn];
ll solve()
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i - 1;
        int r = n - i;
        int tmp = 2 * i - n - 1;
        if (r <= l)
        {
            cnt[i] = nCm(i - 1, n - i) * fac[n - i] % mod * fac[tmp] % mod * qpow(ifac[2], tmp / 2LL, mod) % mod * ifac[tmp / 2] % mod;
            sum = (sum + cnt[i]) % mod;
        }
        else
        {
            cnt[i] = 0;
        }
    }
    sum = qpow(sum, mod - 2, mod);
    for (int i = 1; i <= n; i++)
    {
        
        printf("%lld", cnt[i] * sum % mod);
        if (i == n)
            printf("\n");
        else
            printf(" ");
    }
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    init(maxn - 5);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        solve();
    }
    return 0;
}