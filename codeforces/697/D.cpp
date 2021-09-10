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
const int maxn = 2e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int tmp[maxn];
ll a[maxn], b[maxn];
bool cmp(ll a, ll b) { return a > b; }
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
        read(n, m);
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            read(tmp[i]);
        }
        int tot1 = 0, tot2 = 0;
        a[0] = b[0] = 0;
        for (int i = 1, x; i <= n; i++)
        {
            read(x);
            if (x == 1)
            {
                a[++tot1] = tmp[i];
            }
            else
            {
                b[++tot2] = tmp[i];
            }
        }
        sort(a + 1, a + 1 + tot1, cmp);
        sort(b + 1, b + 1 + tot2, cmp);
        for (int i = 1; i <= tot1; i++)
            a[i] += a[i - 1];
        for (int i = 1; i <= tot2; i++)
            b[i] += b[i - 1];
        int ans = INF;
        if (a[tot1] + b[tot2] < m)
        {
            printf("-1\n");
        }
        else
        {

            for (int i = 0; i <= tot1; i++)
            {
                if (a[i] >= m)
                {
                    ans = min(ans, i);
                    break;
                }
                int pos = lower_bound(b + 1, b + 1 + tot2, m - a[i]) - b;
                if (pos == tot2 + 1)
                    continue;
                ans = min(ans, i + pos * 2);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}