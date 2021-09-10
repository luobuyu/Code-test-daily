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

struct Node
{
    double a[maxn];
    int w;
    bool operator<(const Node &x) const
    {
        return w < x.w;
    }
} node[maxn];
int p[maxn];
int ans, cnt;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lf", &node[i].a[j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &node[i].w);
    }
    sort(node + 1, node + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (fabs(node[i].a[j]) < eqs)
            {
                continue;
            }
            if (!p[j])
            {
                p[j] = i;
                cnt++;
                ans += node[i].w;
                break;
            }
            else
            {
                // 前面的已经加入的花费更少，肯定是把后面加入的消掉
                double tmp = node[i].a[j] / node[p[j]].a[j];
                for (int k = j; k <= m; k++)
                {
                    node[i].a[k] -= tmp * node[p[j]].a[k];
                }
            }
        }
    }

    printf("%d %d\n", cnt, ans);
    return 0;
}