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
int t, n, m, k;
int dp[maxn][maxn];
struct Node
{
    int a, b;
} a[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, m, k);
    for(int i = 1; i <= k; i++)
    {
        read(a[i].a, a[i].b);
    }
    for(int i = 1; i <= k; i++)
    {
        for(int j = n; j >= 0; j--)
        {
            for(int p = m - 1; p >= 0; p--)
            {
                if(j - a[i].a >= 0 && p - a[i].b >= 0)
                {
                    dp[j][p] = max(dp[j][p], dp[j - a[i].a][p - a[i].b] + 1);
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= n; i++)
    {
        for(int j= 0; j <= m - 1; j++)
        {
            if(dp[i][j] == dp[n][m - 1])
            {
                ans = min(ans, j);
            }
        }
    }
    printf("%d %d\n", dp[n][m - 1], m - ans);
    return 0;
}