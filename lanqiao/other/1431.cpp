#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = nextChar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = nextChar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = nextChar();
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
const int maxn = 2e2 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    for (int i = 0; i < n; i++)
    {
        read(a[i]);
    }
    int ans = 0;
    bool flag = false;
    while (!flag)
    {
        flag = true;
        for (int i = 0; i < n; i++)
        {
            a[i] /= 2;
        }
        int tmp = a[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            a[i] += a[i - 1];
        }
        a[0] += tmp;
        for (int i = 0; i < n; i++)
        {
            if (a[i] & 1)
            {
                ans++;
                a[i]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] != a[0])
                flag = false;
        }
    }
    printf("%d\n", ans);
    return 0;
}