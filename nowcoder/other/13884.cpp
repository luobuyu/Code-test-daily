// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
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

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e6 + 10;
const int maxm = 1e5 + 10;
int t;
ll n, m, k;
ll inv[maxn];
void init(int n)
{
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod; // -k 写作了 p - k  
    }
}
ll Cnm(ll n, ll m)
{
    if (n < m)
        return 0;
    if (n - m < m)
        m = n - m;
    ll a = 1;
    for (int i = 0; i < m; ++i)
    {
        a = a * (n - i) % mod * inv[i + 1] % mod;
    }
    return a;
}

ll qpow(ll a, ll b)
{
    ll ans = 1, tmp = a;
    while (b)
    {
        if (b & 1)
            ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tcase;
    read(tcase);
    init(1e6 + 1);
    while (tcase--)
    {
        read(n, m, k);
        fk[0] = k;
        for (int i = 1; i <= k; ++i)
        {
            fk[i] = i * qpow(i - 1, n - 1) % mod;
        }
        ll ans = 0;
        ll flag = 1;
        ll cki = inv[k + 1];
        for (int i = 0, flag = 1; i < k; ++i, flag = -flag)
        {
            cki = cki * (k - i + 1) % mod * inv[i] % mod;
            ans = (ans + flag * (k - i) * qpow(k - i - 1, n - 1) % mod * cki + mod) % mod;
        }
        ans = ans * Cnm(m, k) % mod;
        cout << ans << endl;
    }
    return 0;
}