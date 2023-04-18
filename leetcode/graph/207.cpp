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
    vector<vector<int>> g;
    bool hasCircle = false;
    vector<bool> vis;
    vector<bool> path;
    void dfs(int u)
    {
        if (path[u])
        {
            hasCircle = true;
            return;
        }
        if (hasCircle || vis[u])
            return;
        path[u] = true;
        vis[u] = true;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            dfs(v);
        }
        path[u] = false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        g.resize(numCourses);
        path.resize(numCourses);
        vis.resize(numCourses);
        int m = prerequisites.size();
        for (int i = 0; i < m; ++i)
        {
            int v = prerequisites[i][0], u = prerequisites[i][1];
            g[u].emplace_back(v);
        }
        for (int i = 0; i < numCourses; ++i)
        {
            if (vis[i])
                continue;
            dfs(i);
        }
        return !hasCircle;
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
    vector<vector<int>> a = {{1, 0}, {0, 1}};
    solution.canFinish(2, a);
    return 0;
}