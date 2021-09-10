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
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
int q, d;
bool check(int x)
{
    int tmp = x;
    if (x >= d * 10)
        return true;
    for (int i = 1; i <= 10; i++)
    {
        int ss = x - a[i];
        if (ss >= 0 && ss % 10 == 0)
        {
            return true;
        }
    }
    return false;
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

        read(q, d);
        for (int i = 1; i <= 10; i++)
        {
            a[i] = i * d;
        }
        for (int i = 1; i <= q; i++)
        {
            read(n);
            printf("%s\n", (check(n) ? "yes" : "no"));
        }
    }
    return 0;
}