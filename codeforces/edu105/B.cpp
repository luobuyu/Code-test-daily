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
int u, r, d, l;

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
        read(n, u, r, d, l);
        if (u <= n - 2 && r <= n - 2 && d <= n - 2 && l <= n - 2)
        {
            printf("YES\n");
            continue;
        }
        bool flag = false;
        for (int ia = 0; ia <= 1; ia++)
        {
            for (int ib = 0; ib <= 1; ib++)
            {
                for (int ic = 0; ic <= 1; ic++)
                {
                    for (int id = 0; id <= 1; id++)
                    {
                        int tmpu = u - ia - ib;
                        int tmpr = r - ib - ic;
                        int tmpd = d - ic - id;
                        int tmpl = l - id - ia;
                        if (tmpu <= n - 2 && tmpr <= n - 2 && tmpd <= n - 2 && tmpl <= n - 2 && tmpu >= 0 && tmpr >= 0 && tmpd >= 0 && tmpl >= 0)
                        {
                            flag = true;
                        }
                    }
                }
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}