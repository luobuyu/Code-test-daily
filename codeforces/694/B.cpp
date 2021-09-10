#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
ll a[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    ll x;
    while (tcase--)
    {
        read(n, x);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        int p = 0;
        int index = -1;
        int times = INF;
        for (int i = 1; i <= n; i++)
        {
            p = 0;
            int tmp = a[i];
            while (tmp % x == 0)
            {
                p++;
                tmp /= x;
            }
            if (p < times)
            {
                times = p;
                index = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i < index)
                ans += a[i] * (ll)(times + 2);
            else
                ans += a[i] * (ll)(times + 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}