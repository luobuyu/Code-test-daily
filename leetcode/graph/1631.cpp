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
    vector<int> dis;
    vector<bool> vis;
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int dijkstra(int start, int end, vector<vector<int>> &height)
    {
        dis.resize(n * m, INF);
        vis.resize(n * m, false);
        priority_queue<pair<int, int>> q;
        q.push({0, 0});
        dis[0] = 0;
        while (q.size())
        {
            auto out = q.top();
            q.pop();
            if (vis[out.second])
                continue;
            vis[out.second] = true;
            int ux = out.second / m, uy = out.second % m;
            for (int i = 0; i < 4; ++i)
            {
                int vx = ux + dx[i];
                int vy = uy + dy[i];
                if (vx < 0 || vy < 0 || vx >= n || vy >= m)
                    continue;
                int w = fabs(height[ux][uy] - height[vx][vy]);
                if (max(dis[out.second], w) < dis[vx * m + vy])
                {
                    dis[vx * m + vy] = max(dis[out.second], w);
                    q.push({-max(-out.first, dis[vx * m + vy]), vx * m + vy});
                }
            }
        }
        return dis[end];
    }
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        n = heights.size();
        m = heights[0].size();
        return dijkstra(0, n * m - 1, heights);
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