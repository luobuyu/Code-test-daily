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
const int maxn = 5e1 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

int dp[maxn][maxn][maxn][maxn];
int a[maxn][maxn];
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
            read(a[i][j]);
        }
    }

    for(int x1 = 1; x1 <= n; x1++)
    {
        for(int x2 = 1; x2 <= n; x2++)
        {
            for(int y1 = 1; y1 <= m; y1++)
            {
                for(int y2 = 1; y2 <= m; y2++)
                {
                    int w = a[x1][y1];
                    if(!(x1==x2 && y1 == y2))
                    {
                        w += a[x2][y2];
                    }

                    dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], max(
                        max(max(dp[x1 - 1][y1][x2 - 1][y2], dp[x1 - 1][y1][x2][y2 - 1]), 
                        dp[x1][y1 - 1][x2 - 1][y2]), 
                        dp[x1][y1 - 1][x2][y2 - 1]) + w);
                }
            }
        }
    }
    printf("%d\n", dp[n][m][n][m]);
    return 0;
}