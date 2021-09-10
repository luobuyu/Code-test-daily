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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

int h[maxn];

bool check()
{
    if (h[1])
        return false;
    for (int i = 2; i <= n; i++)
    {
        if (h[i - 1] > h[i] || h[i] >= n)
            return false;
    }
    return true;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(h[i]);
        }
        if (check())
        {
            ll ans = 1, empty = 0;
            for (int i = 2; i <= n; i++)
            {
                if (h[i] > h[i - 1])
                {
                    ans = ans * 2 % mod;
                    empty += h[i] - h[i - 1] - 1;
                }
                else if (h[i] == h[i - 1])
                {
                    ans = ans * empty % mod;
                    empty--;
                }
            }
            printf("%lld\n", ans);
        }
        else
            printf("0\n");
    }
    return 0;
}