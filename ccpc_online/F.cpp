#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template<class T> inline void read(T&x)
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

    template<class T, class ..._T> inline void read(T&x, _T &...y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO

void print128(__int128 x)
{
    if (x < 0) { putchar('-'); x = -x; }
    static char str[40]; int cnt = 0;
    while (x > 9) { str[cnt ++] = (x % 10) ^ 48; x /= 10;}
    str[cnt ++] = x ^ 48;
    while (cnt --) putchar(str[cnt]);
}

#define VAR(var) ""#var" = " << var

using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;

using lll = __int128;
int t, n, m, k, a;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    read(t);
    while (t --)
    {
        read(n, m, k);
        lll xx = 0;
        auto close = n;
        while (m --)
        {
            read(a);
            close = min(close, a);
            xx += 2 * abs(k - a);
        }
        xx = xx + k + close - abs(k - close) - 2;
        // cerr << VAR(close) << ", ";
        print128(xx);
        puts("");
    }
    
    return 0;
}