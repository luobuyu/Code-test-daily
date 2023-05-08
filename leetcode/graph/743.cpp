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
    vector<vector<pair<int, int>>> g; // v, w
    vector<int> dis;
    vector<bool> vis;
    void dijkstra(int s)
    {
        priority_queue<pair<int, int>> q;
        dis[s] = 0;
        q.push({-dis[s], s});
        while (q.size())
        {
            int u = q.top().second;
            q.pop();
            if (vis[u])
                continue;
            vis[u] = true;
            for (int i = 0; i < g[u].size(); ++i)
            {
                int v = g[u][i].first;
                int w = g[u][i].second;
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    q.push({-dis[v], v});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        g.resize(n);
        int m = times.size();
        for (int i = 0; i < m; ++i)
        {
            g[times[i][0] - 1].emplace_back(make_pair(times[i][1] - 1, times[i][2]));
        }
        dis.resize(n, 0x3f3f3f3f);
        vis.resize(n, false);
        dijkstra(k - 1);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, dis[i]);
        }
        if (ans == 0x3f3f3f3f)
            return -1;
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

    return 0;
}