#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e7 + 10;
const ll mod = 1e9 + 7;
ll pow2inv[maxn];
ll a[maxn];
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
    pow2inv[0] = 1;
    pow2inv[1] = qpow(2, mod - 2, mod); // 5e8 + 4
    a[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pow2inv[i] = pow2inv[i - 1] * pow2inv[1] % mod;
        a[i] = (a[i-1] *(1 + mod - pow2inv[i]) % mod) % mod;
    } 

    for (int i = 2; i <= n; i++)
    {
        a[i] ^= a[i - 1];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    init(maxn - 5);
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}