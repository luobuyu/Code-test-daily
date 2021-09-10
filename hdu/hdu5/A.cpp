#include <bits/stdc++.h>
#define ll long long
#define ull long long
using namespace std;
const ll mod = 998244353;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 6e6 + 10;
const int maxm = 1e5 + 10;
int t, n, m;
ll inv[maxn], sum[maxn];
void init(int n)
{
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;
    }
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] += (sum[i - 1] + inv[i] * inv[i] % mod) % mod;
    }
}

ll solve(int t)
{
    return (3 * inv[t]) % mod * sum[t] % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    init(maxn - 5);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%lld\n", solve(n));
    }
    return 0;
}
