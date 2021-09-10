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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
unordered_map<int, bool> mp;
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
        read(n, k);
        mp.clear();
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
            mp[a[i]] = 1;
        }
        if (k == 0)
            printf("%d\n", n);
        else
        {
            bool flag = true;

            sort(a + 1, a + 1 + n);
            int x;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] != i - 1)
                {
                    flag = false;
                    x = i - 1;
                    break;
                }
            }
            ll ans = n;
            if (flag)
                ans += k;
            else
            {
                if (!mp.count((x + a[n] - 1) / 2 + 1))
                {
                    ans += 1;
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}