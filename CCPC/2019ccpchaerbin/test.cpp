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
int a[maxn];
int b[maxn];
int main()
{
    // // #define COMP_DATA
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    // #endif
    n = 5;
    for (int i = 1; i <= n; i++)
    {
        read(b[i]);
        a[i] = i;
    }
    do
    {
        bool flag = true;
        int maxx = 0, minx = 100;
        for (int i = 1; i <= n; i++)
        {
            maxx = max(maxx, a[i]);
            minx = min(minx, a[i]);
            if (maxx - minx != b[i])
            {
                flag = false;
                break;
            }
        }

        if (flag)
            for (int i = 1; i <= n; i++)
            {
                printf("%d%c", a[i], " \n"[i == n]);
            }

    } while (next_permutation(a + 1, a + n + 1));

    return 0;
}