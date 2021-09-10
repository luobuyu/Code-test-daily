#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    const static int maxbuf = 1e6;
    inline char nextChar()
    {
        static char buf[maxbuf], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, maxbuf, stdin), p1 == p2) ? EOF : *p1++;
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
int c;
struct Node
{
    int c, v;
} node[maxn][10];
int dp[maxn];
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
        read(n, c);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                read(node[i][j].c, node[i][j].v);
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            for (int j = c; j >= 0; j--)
            {
                for (int k = 1; k <= 4; k++)
                {
                    if (j - node[i][k].c >= 0)
                        dp[j] = max(dp[j], dp[j - node[i][k].c] + node[i][k].v);
                }
            }
        }
        printf("%d\n", dp[c]);
    }
    return 0;
}