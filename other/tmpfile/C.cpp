#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e6 + 10;
ll inv[N], f[N];
void get_inv(int n, int p)
{
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = inv[p % i] * (p - p / i) % p;
}
ll C(int x, int y)
{
    return f[x] * inv[x - y] % mod * inv[y] % mod;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    int T, n, m, k;
    get_inv(N - 1, mod);
    for (int i = 1; i < N; i++)
        inv[i] = inv[i] * inv[i - 1] % mod;
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i - 1] * i % mod;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        ll ans = 0;
        for (int i = 0; i <= min(n, m) - k; i++)
        {
            ans = (ans + C(k + i - 1, k - 1) * C(n - i - 1, k - 1) % mod * C(m - i - 1, k - 1) % mod) % mod; //xy个数x个数y个数
        }
        printf("%lld\n", ans);
    }
}
