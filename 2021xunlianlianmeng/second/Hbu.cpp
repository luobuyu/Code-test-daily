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
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e2 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
bitset<maxn> a[maxn];
bool flag[maxn];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        flag[i] = false;
        a[i].reset();
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase = 0;
    while (++tcase)
    {
        read(n, t, m);
        init();
        if (!(n && t && m))
            break;
        for (int i = 1, x, y; i <= n; i++)
        {
            read(x);
            while (x--)
            {
                read(y);
                a[i].set(y - 1);
            }
            char ch = getchar();
            if (ch == 'Y')
                flag[i] = 1;
        }
        int ans = 1e9;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                bitset<maxn> tmp(0);
                bool f = 0;
                for (int k = i; k <= j; k++)
                {
                    tmp |= a[k];
                    f |= flag[k];
                    if (tmp.count() == m && f)
                    {
                        if (t < i)
                        {
                            ans = min(ans, (j - t) * 2);
                        }
                        else if (t >= i && t <= j)
                        {
                            ans = min(ans, (j - i) * 2);
                        }
                        else
                        {
                            ans = min(ans, (t - i) * 2);
                        }
                    }
                }
            }
        }
        printf("Test case #%d: ", tcase);
        if (ans < 1e9)
        {
            printf("%d\n\n", ans);
        }
        else
        {
            printf("Impossible\n\n");
        }
    }
    return 0;
}