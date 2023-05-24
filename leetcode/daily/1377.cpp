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

struct Node
{
    int u;
    double p;
    int time;
};
class Solution
{
public:
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> g;
    int n, m;
    double bfs(int start, int end, int time)
    {
        queue<Node> q; // id, 概率
        vector<bool> vis(n, false);
        q.push({start, 1, 0});
        vis[start] = true;
        while (q.size())
        {
            auto out = q.front();
            q.pop();
            int u = out.u;
            double p = out.p;
            if (out.time > time)
                continue;
            int out_deg = g[u].size() - (u != 1);
            if (u == end)
            {
                if (out_deg == 0 || out.time == time)
                    return p;
            }
            // if(vis[u]) continue;
            for (int i = 0; i < g[u].size(); ++i)
            {
                int v = g[u][i];
                if (vis[v])
                    continue;
                vis[v] = true;
                q.push({v, p * 1.0 / out_deg});
            }
        }
        return 0;
    }
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        this->n = n;
        this->m = edges.size();
        g.resize(n);
        for (int i = 0, u, v; i < m; ++i)
        {
            u = edges[i][0] - 1, v = edges[i][1] - 1;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        return bfs(0, target - 1, t);
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