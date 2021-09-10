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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
const double pi = acos(-1);
int n, m;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, m);
    double ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            for (int k = 0; k <= m; k++)
                ans += min(i + j * 1.0, i * k * pi / m + j - i) * (k == 0 || k == m ? 1 : 2) * (j == i ? 1 : 2);
    ans *= 2 * m;
    if (m != 1)
    {
        for (int i = 1; i <= n; i++)
            ans += 4 * m * i;
    }
    printf("%.15lf\n", ans / 2);
    return 0;
}
