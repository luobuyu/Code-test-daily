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
class Solution
{
public:
    const static int maxn = 1e1 + 10;
    const static int maxm = 1e5 + 10;
    vector<int> adj[maxn];
    int dfs(int u, int fa, int mask)
    {
        mask &= ~(1 << u);
        int dep = 0;
        for (int i = 0, v; i < adj[u].size(); ++i)
        {
            v = adj[u][i];
            if (v == fa)
                continue;
            if (mask & (1 << v))
            {
                dep = max(dep, dfs(v, u, mask) + 1);
            }
        }
        return dep;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges)
    {
        vector<int> ans(n - 1);
        // 建图
        for (auto &edge : edges)
        {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        // 直接枚举所有的子树，判断是否连通
        int all = (1 << n) - 1;
        for (int mask = 1; mask <= all; ++mask)
        {
            // i 是子树的二进制编码
            // bfs 该子树，判断是否连通
            int vis = mask;
            // 找到一个根
            int root;
            for (int i = 0; i < n; ++i)
            {
                if ((1 << i) & vis)
                {
                    root = i;
                    break;
                }
            }
            // root 是最大的顶点
            queue<int> q;
            q.push(root);
            vis &= ~(1 << root);
            int y;
            while (q.size())
            {
                y = q.front();
                q.pop();
                for (int i = 0, v; i < adj[y].size(); ++i)
                {
                    v = adj[y][i];
                    if (vis & (1 << v)) // 有边
                    {
                        vis &= ~(1 << v);
                        q.push(v);
                    }
                }
            }
            if (vis != 0) // 不是合法子树
                continue;
            int dep = dfs(y, -1, mask);
            if (dep == 0)
                continue;
            ans[dep - 1]++;
        }
        return ans;
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
    read(n, m);
    vector<vector<int>> a;
    for (int i = 0, x, y; i < m; ++i)
    {
        vector<int> b;
        read(x, y);
        b.emplace_back(x);
        b.emplace_back(y);
        a.emplace_back(b);
    }
    for (auto &u : solution.countSubgraphsForEachDiameter(n, a))
    {
        cout << u << endl;
    }
    return 0;
}