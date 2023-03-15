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
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;

    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        int m = roads.size();
        vector<int> deg(n);
        for (int i = 0, u, v; i < m; ++i)
        {
            u = roads[i][0];
            v = roads[i][1];
            deg[u]++;
            deg[v]++;
        }
        vector<int> a;

        for (int i = 0; i < n; ++i)
        {
            a.push_back(i);
        }
        sort(a.begin(), a.end(), [&](const int &x, int &y)
             { return deg[x] > deg[y]; });
        int ans = 0;
        int u, v;
        bool flag; // 没有边
        for (int i = 0, deg_u = deg[a[i]]; i < a.size() - 1 && deg_u == deg[a[i]]; ++i)
        {
            u = a[i];
            for (int j = i + 1, deg_j = deg[a[j]]; j < a.size() && deg_j == deg[a[j]]; ++j)
            {
                flag = false;
                v = a[j];
                for (int i = 0, uu, vv; i < m; ++i)
                {
                    uu = roads[i][0];
                    vv = roads[i][1];
                    if (uu == u && vv == v ||
                        uu == v && vv == u)
                    {
                        flag = true;
                        break;
                    }
                }
                ans = max(ans, deg[u] + deg[v] - flag);
                if (!flag)
                {

                    break;
                }
            }
            if (!flag)
            {
                break;
            }
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
    vector<vector<int>> roads;
    for (int i = 0, u, v; i < m; ++i)
    {
        vector<int> a;
        read(u);
        a.emplace_back(u);
        read(v);
        a.emplace_back(v);
        roads.emplace_back(a);
    }
    cout << solution.maximalNetworkRank(n, roads) << endl;
    return 0;
}