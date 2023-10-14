// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
vector<int> g[maxn];
int dp[maxn][maxm]; // dp[i][j], 表示分配给节点 i, 体积 j 能达到的最大价值
// dp[u][j] = dp[u][j]
int a[maxn][2];
void dfs(int u)
{
    // for (int j = a[u][0]; j <= m; ++j)
    //     dp[u][j] += a[u][1];
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        dfs(v);
        // 节点 u 必须被选择，否则孩子节点无法选择
        for (int j = m; j >= a[u][0]; --j)
        {
            // 枚举分配给子树的体积
            for (int k = 0; k <= j - a[u][0]; ++k)
            {
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
            }
        }
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    read(n, m);
    int root;
    for (int i = 1, p, v, w; i <= n; ++i)
    {
        read(v, w, p);
        a[i][0] = v, a[i][1] = w;
        dp[i][v] = w;
        if (p == -1)
        {
            root = i;
            continue;
        }
        g[p].emplace_back(i);
    }
    dfs(root);
    cout << dp[root][m] << endl;
    return 0;
}