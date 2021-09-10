#include <bits/stdc++.h>
#define ll long long
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

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 998244353;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

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
struct Node
{
    ll l, r;
    bool operator<(const Node &b) const
    {
        return l + r < b.l + b.r;
    }
} a[maxn];
ll inv2;
ll invlen[maxn];
ll solve(int x, int y)
{
    int l1 = a[x].l, r1 = a[x].r, l2 = a[y].l, r2 = a[y].r;
    ll ans = 0;

    if (l1 <= l2 && r1 <= r2 && r1 >= l2) // l1 <= l2 <= r1 <= r2
    {
        ans = (r1 - l2 + 1) * (r1 - l2) % mod * inv2 % mod;
    }
    else if (l1 <= l2 && r2 <= r1) // l1 <= l2 <= r2 <= r1
    {
        ans = (r2 - l2 + 1) * (r2 - l2) % mod * inv2 % mod;
        ans = (ans + (r1 - r2) * (r2 - l2 + 1) % mod) % mod;
    }
    else if (l1 >= l2 && r1 <= r2) // l2 <= l1 <= r1 <= r2
    {
        ans = (r1 - l1 + 1) * (l1 - l2 + r1 - l2) % mod * inv2 % mod;
    }

    return ans * invlen[x] % mod * invlen[y] % mod;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(a[i].l, a[i].r);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        invlen[i] = qpow(a[i].r - a[i].l + 1, mod - 2, mod);
    }
    ll ans = 0;
    inv2 = qpow(2, mod - 2, mod);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ans = (ans + solve(i, j)) % mod;
        }
    }
    cout << ans << endl;

    return 0;
}