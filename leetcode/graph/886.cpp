// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
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
int t, n, m, k;
auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;
    bool ok = true;
    vector<bool> vis;
    vector<bool> color;
    vector<vector<int>> g;
    void dfs(int u)
    {
        if (!ok)
            return;
        vis[u] = true;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (vis[v])
            {
                if (color[u] == color[v])
                    ok = false;
            }
            else
            {
                color[v] = !color[u];
                dfs(v);
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        g.resize(n);
        vis.resize(n);
        color.resize(n);
        for (int i = 0; i < dislikes.size(); ++i)
        {
            g[--dislikes[i][0]].emplace_back(--dislikes[i][1]);
            g[dislikes[i][1]].emplace_back(dislikes[i][0]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }
        return ok;
    }
};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;

    return 0;
}