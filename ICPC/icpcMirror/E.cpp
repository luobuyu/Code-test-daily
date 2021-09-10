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
ll a[maxn], d[maxn];
ll minx[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    read(n, k);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        a[i] += a[i - 1];
    }
    minx[0] = INF_LL;
    for (int i = 1; i <= n; i++)
    {
        read(d[i]);
        minx[i] = min(d[i], minx[i - 1]);
    }

    ll ans = 0;
    if (k == 0)
    {
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans, a[n] - a[i - 1] - d[i]);
        }
    }
    else if(k == 1)
    {
        for(int i = 1; i < n; i++)
        {
            ans = max(ans, max(0ll, a[i] - minx[i]) + max(0ll, a[n] - a[i] - d[i + 1]));
        }

        for(int i = 2; i < n; i++)
        {
            ans = max(ans, a[n] - (a[i] - a[i - 1]) - d[1] + max(0ll, a[i] - a[i - 1] - d[i]));
        }
    }
    else
    {
        ans = max(0ll, max(a[n] - minx[n - 1], max(0ll, a[n] - a[n - 1] - d[n])));
    }
    printf("%lld\n", ans);

    return 0;
}

/*
6 1
1 10 10 5 20 100
1000000 1 10 10 100 1000000

144
*/