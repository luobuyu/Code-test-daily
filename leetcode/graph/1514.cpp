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
    std::cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    vector<vector<pair<int, int>>> g;
    vector<bool> vis;
    vector<double> dis;
    double djikstra(int s, int e)
    {
        priority_queue<pair<double, int>> q;
        dis[s] = 1;
        q.push({dis[s], s});
        while (q.size())
        {
            auto out = q.top();
            q.pop();
            int u = out.second;
            if (vis[u])
                continue;
            vis[u] = true;
            for (int i = 0; i < g[u].size(); ++i)
            {
                int v = g[u][i].first, w = g[u][i].second;
                if (dis[u] * w < dis[v])
                {
                    dis[v] = dis[u] * w;
                    q.push({dis[v], v});
                }
            }
        }
        return dis[e];
    }
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        g.resize(n);
        dis.resize(n, 0);
        vis.resize(n, false);
        int m = edges.size();
        for (int i = 0, u, v, w; i < m; ++i)
        {
            u = edges[i][0], v = edges[i][1], w = succProb[i];
            g[u].emplace_back(make_pair(v, w));
            g[v].emplace_back(make_pair(u, w));
        }
        return djikstra(start, end);
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