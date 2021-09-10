#include <bits/stdc++.h>
#define ll long long
#define lll long long
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
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
ll a[maxn];

bool check(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (x % a[i] == 0)
            return true;
    }
    return false;
}

ll phi(ll x)
{
    ll ans = x;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ans = ans / i * (i - 1); // p^k * (p - 1)
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        ans = ans / x * (x - 1);
    return ans;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int Tcase;
    read(Tcase);
    for (int tcase = 1; tcase <= Tcase; tcase++)
    {
        read(n, m);
        for (int i = 1, x; i <= n; i++)
        {
            read(x);
            a[i] = __gcd(x, m);
        }
        n = unique(a + 1, a + 1 + n) - a - 1;
        ll ans = 0;
        for (int i = 1; i * i <= m; i++)
        {
            if (m % i == 0)
            {
                if (check(i))
                {
                    ans += phi(m / i);
                }
                if (i == 1 || i * i == m)
                    continue;
                if (check(m / i))
                {
                    ans += phi(i);
                }
            }
        }
        ans = ans * m / 2;
        printf("Case #%d: %lld\n", tcase, ans);
    }
    return 0;
}