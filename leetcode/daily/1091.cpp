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
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dis(n, vector<int>(m, INF));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};
        q.push({0, 0});
        dis[0][0] = 0;
        vis[0][0] = true;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        while (q.size())
        {
            auto out = q.front();
            q.pop();
            if (out.first == n - 1 && out.second == n - 1)
            {
                return dis[n - 1][n - 1];
            }
            for (int i = 0; i < 8; ++i)
            {
                int newx = out.first + dx[i];
                int newy = out.second + dy[i];
                if (newx < 0 || newx >= n || newy < 0 || newy >= n || grid[newx][newy] == 1 || vis[newx][newy])
                    continue;
                dis[newx][newy] = dis[out.first][out.second] + 1;
                q.push({newx, newy});
                vis[newx][newy] = true;
            }
        }
        return -1;
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