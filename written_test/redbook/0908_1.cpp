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
const int maxn = 5e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
char a[maxn][maxn];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int dp[maxn][maxn];
bool vis[maxn][maxn];
int dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    if (vis[x][y])
        return 1;
    vis[x][y] = true;
    if (a[x][y] == 'L')
        return dp[x][y] = dfs(x, y - 1);
    else if (a[x][y] == 'R')
        return dp[x][y] = dfs(x, y + 1);
    else if (a[x][y] == 'U')
        return dp[x][y] = dfs(x - 1, y);
    else if (a[x][y] == 'D')
        return dp[x][y] = dfs(x + 1, y);
    return 0;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ans += dfs(i, j);
            // cout << i << ", " << j << ", " << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}