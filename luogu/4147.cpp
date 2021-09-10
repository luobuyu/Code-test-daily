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
int a[maxn][maxn];
int lef[maxn][maxn], righ[maxn][maxn], height[maxn][maxn];
inline int Readc()
{
    char c = getchar();
    while (c != 'R' && c != 'F')
        c = getchar();
    if (c == 'F')
        return 1;
    return 0;
} //F能用，E不能用
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif

    read(n, m);
    char ch;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%c ", &ch);
            if (ch == 'F')
            {
                a[i][j] = 1;
                height[i][j] = 1;
                lef[i][j] = righ[i][j] = j;
            }
            else
            {
                a[i][j] = 0;
            }

            
        }
    }

    // 对行进行递推	左
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (a[i][j] == a[i][j - 1] && a[i][j] == 1)
            {
                lef[i][j] = lef[i][j - 1];
            }
        }
    }
    // 对行进行递推	右
    for (int i = 1; i <= n; i++)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (a[i][j] == a[i][j + 1] && a[i][j] == 1)
                righ[i][j] = righ[i][j + 1];
        }
    }
    // 对列进行递推	列
    // 每次递推一行
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i > 1 && a[i][j] == a[i - 1][j] && a[i][j] == 1)
            {
                height[i][j] = height[i - 1][j] + 1;
                lef[i][j] = max(lef[i][j], lef[i - 1][j]);
                righ[i][j] = min(righ[i][j], righ[i - 1][j]);
            }
            ans = max(ans, (righ[i][j] - lef[i][j] + 1) * height[i][j]);
        }
    }



    printf("%d\n", 3 * ans);

    return 0;
}