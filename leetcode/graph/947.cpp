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
    struct UF
    {
        vector<int> fa;
        int count;
        UF(int n) : fa(n), count(n)
        {
            for (int i = 0; i < n; ++i)
                fa[i] = i;
        }
        int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
        void unite(int u, int v)
        {
            int up = find(u), vp = find(v);
            if (up != vp)
            {
                fa[up] = vp;
                count--;
            }
        }
        bool connect(int u, int v) { return find(u) == find(v); }
        int getCount() { return count; }
    };
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            int x = stones[i][0], y = stones[i][1] + 10000;
            if (!mp.count(x))
            {
                stones[i][0] = x = mp[x] = cnt++;
            }
            if (!mp.count(y))
            {
                stones[i][1] = y = mp[y] = cnt++;
            }
        }
        UF uf(cnt);
        for (int i = 0; i < n; ++i)
        {
            int x = stones[i][0], y = stones[i][1];
            uf.unite(x, y);
        }
        int ans = 0;
        for (auto &item : mp)
        {
            if (uf.find(item.first))
            {
                ans++;
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

    return 0;
}