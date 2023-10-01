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
const int maxn = 3e4 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
vector<int> g[maxn];
int indeg[maxn];
int nums[maxn];
int cnt = 0;
bitset<maxn> dp[maxn];
void topoSort()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!indeg[i])
            q.push(i);
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        nums[++cnt] = u;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            indeg[v]--;
            if (!indeg[v])
            {
                q.push(v);
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
    for (int i = 0, u, v; i < m; ++i)
    {
        read(u, v);
        indeg[v]++;
        g[u].emplace_back(v);
    }
    topoSort();
    for (int i = n; i >= 1; --i)
    {
        int u = nums[i];
        dp[u][u] = 1;
        for (int j = 0; j < g[u].size(); ++j)
        {
            int v = g[u][j];
            dp[u] |= dp[v];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << dp[i].count() << endl;
    }
    return 0;
}