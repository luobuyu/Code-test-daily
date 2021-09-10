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
    inline void read(T &x, _T &...y)
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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
ll p[maxn];
ll a[maxn];
void lbinsert(ll x)
{
    for (int i = 55; i >= 0; i--)
    {
        if (!(x >> (ll)i)) // x的第i位是0
            continue;
        if (!p[i])
        {
            p[i] = x;
            break;
        }
        x ^= p[i];
    }
}
ll lbquery()
{
    ll maxx = 0;
    for (int i = 62; i >= 0; i--)
    {
        if ((maxx ^ p[i]) > maxx)
        {
            maxx ^= p[i];
        }
    }
    return maxx;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    ll x;
    for (int i = 1; i <= n; i++)
    {
        read(x);
        lbinsert(x);
    }
    printf("%lld\n", lbquery());
    return 0;
}