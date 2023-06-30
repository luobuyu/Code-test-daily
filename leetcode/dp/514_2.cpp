// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{
    static string buf_line;
    static int _i;
    static int _n;

    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        char ch = buf_line[_i++];
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = buf_line[_i++];
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = buf_line[_i++];
        }
        x *= flag;
        return true;
    }

    template <class T, class... _T>
    inline bool read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline bool getline()
    {
        if (!getline(cin, buf_line))
            return false;
        _i = 0, _n = buf_line.length();
        return true;
    }
    template <class T>
    inline void show(T *a, int n)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            cout << a[i];
        }
        cout << "]";
    }

    template <class T, std::size_t Num>
    inline void show(T a[][Num], int n, int m)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            show(a[i], m);
        }
        cout << "]";
    }
} // namespace FAST_IO
using namespace FAST_IO;

int init = []
{
    /*********** fast_read ***************/
    freopen("user.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*************************************/

    int dp[100000][2] = {};
    int v, ans;
    string s;
    for (; getline();)
    {
        for (int i = 0; read(v); ++i)
        {
            if (i == 0)
            {
                dp[0][0] = v;
                dp[0][1] = 0;
                ans = v;
            }
            else
            {
                dp[i][0] = max(dp[i - 1][0] + v, v);
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + v);
                ans = max(ans, max(dp[i][0], dp[i][1]));
            }
        }
        cout << ans << endl;
    }
    exit(0);
    return 0;
}();

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
    const static int maxn = 1e2 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> pos;
    int dis[maxn][maxn];
    bool vis[maxn][maxn];
    struct Node
    {
        int i, j, step; // key[i], ring[j],
        bool operator<(const Node &p) const
        {
            return step > p.step;
        }
        Node(int i, int j, int step) : i(i), j(j), step(step) {}
    };
    int findRotateSteps(string ring, string key)
    {
        pos.resize(26);
        int n = key.size(), m = ring.size();
        for (int i = 0; i < m; ++i)
            pos[ring[i] - 'a'].emplace_back(i);

        priority_queue<Node> q;
        // key[0], j
        int step;
        memset(dis, 0x3f, sizeof(dis));
        for (auto &j : pos[key[0] - 'a'])
        {
            step = min(j, m - j) + 1;
            q.emplace(Node(0, j, step));
            dis[0][j] = step;
        }
        int ans = INF;
        while (q.size())
        {
            auto out = q.top();
            q.pop();
            if (out.i == n - 1)
                break;
            if (vis[out.i][out.j])
                continue;
            vis[out.i][out.j] = true;
            // 找 out.i 的出边
            if (out.i + 1 >= n)
                break;
            for (auto &j : pos[key[out.i + 1] - 'a'])
            {
                int w = min(abs(out.j - j), m - abs(out.j - j)) + 1;
                if (dis[out.i + 1][j] > dis[out.i][out.j] + w)
                {
                    dis[out.i + 1][j] = dis[out.i][out.j] + w;
                    if (out.i + 1 == n - 1)
                        ans = min(ans, dis[out.i + 1][j]);
                    q.push(Node(out.i + 1, j, dis[out.i + 1][j]));
                }
            }
        }
        return ans;
    }
};

int t, n, m, k;
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