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
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
vector<int> g[maxn];
int dp[maxn][3]; // 0 不建，1建，2 不建但是被覆盖

void dfs(int u, int fa)
{
    dp[u][0] = 0;
    dp[u][1] = 1;
    dp[u][2] = 0;
    bool has_child = false;
    int minx = INF;
    bool flag = false;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if (v == fa)
            continue;
        has_child = true;
        dfs(v, u);
        dp[u][0] += min(dp[v][1], dp[v][2]);
        dp[u][1] += min(dp[v][1], min(dp[v][0], dp[v][2]));
        minx = min(minx, dp[v][1] - dp[v][2]);
        if (dp[v][1] < dp[v][2])
        {
            dp[u][2] += dp[v][1];
            flag = true;
        }
        else
            dp[u][2] += dp[v][2];
    }
    if (!has_child)
    {
        dp[u][0] = 0;
        dp[u][1] = 1;
        dp[u][2] = INF;
    }
    else if (!flag)
    {
        dp[u][2] += minx;
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
    int id = 0, index = 0;
    int x;
    while (cin >> x)
    {
        if (index == 0)
        {
            ++id;
            ++index;
            continue;
        }
        int fa = (index - 1) / 2;
        if (x == 1)
        {
            g[fa].emplace_back(id);
            cout << fa << ", " << id << endl;
            ++id;
        }
        ++index;
    }
    dfs(0, -1);
    for (int i = 0; i < id; ++i)
    {
        cout << i << ", " << dp[i][0] << ", " << dp[i][1] << ", " << dp[i][2] << endl;
    }
    cout << min(dp[0][0], min(dp[0][1], dp[0][2])) << endl;

    return 0;
}