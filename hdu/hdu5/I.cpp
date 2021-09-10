#include <bits/stdc++.h>
#define ll long long
#define ull long long
using namespace std;
const ll mod = 998244353;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 100 + 10;
const int maxm = 1e5 + 10;
int t;
ll n;
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

ll solve(ll n)
{
    ll pow2n = qpow(2, n, mod);
    ll pow3n = qpow(3, n, mod);
    ll pow2ninv = qpow(pow2n, mod - 2, mod);
    return ((pow2n + 1) % mod + 2LL * pow3n % mod * pow2ninv % mod) % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", solve(n));
    }
    return 0;
}