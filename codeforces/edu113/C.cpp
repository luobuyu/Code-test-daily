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
const ll mod = 998244353;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 2e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
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
ll fac[maxn];
int a[maxn];

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    fac[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    while (tcase--)
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        // O(n) 维护最大值和次大值，注意每个数要一致方向判断范围
        int cnt1 = 0, cnt2 = 0;
        int maxx = -1, maxxx = -1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > maxx)
            {
                maxxx = maxx;
                maxx = a[i];
                cnt2 = cnt1;
                cnt1 = 1;
            }
            else if (a[i] == maxx)
            {
                cnt1++;
            }
            else if (a[i] > maxxx)
            {
                maxxx = a[i];
                cnt2 = 1;
            }
            else if (a[i] == maxxx)
            {
                cnt2++;
            }
        }
        if (cnt1 > 1)
        {
            printf("%lld\n", fac[n]);
        }
        else if (cnt1 == 1)
        {
            if (maxx - maxxx > 1)
            {
                printf("0\n");
            }
            else
            {
                printf("%lld\n", cnt2 * qpow(cnt2 + 1, mod - 2) % mod * fac[n] % mod);
            }
        }
    }
    return 0;
}