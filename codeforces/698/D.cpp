#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5, M = 2e4 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;
#define mst(a, b) memset(a, b, sizeof a)
#define PII pair<int, int>
#define fi first
#define se second
#define pb push_back
int t, n;
ll k, a[N];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ll x, g = 0;
        scanf("%d%lld", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for (int i = 2; i <= n; i++)
            g = __gcd(g, a[i] - a[i - 1]);
        puts((k - a[1]) % g == 0 ? "YES" : "NO");
    }
    return 0;
}
