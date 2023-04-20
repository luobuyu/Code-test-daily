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
        UF(int n) : fa(n)
        {
            for (int i = 0; i < n; ++i)
            {
                fa[i] = i;
            }
        }
        int find(int u)
        {
            return fa[u] == u ? u : fa[u] = find(fa[u]);
        }
        void unite(int u, int v)
        {
            int up = find(u), vp = find(v);
            if (up != vp)
                fa[up] = vp;
        }
        bool connect(int u, int v)
        {
            return find(u) == find(v);
        }
    };
    bool equationsPossible(vector<string> &equations)
    {
        int n = 26;
        UF uf(n + n);
        for (int i = 0; i < equations.size(); ++i)
        {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            if (equations[i][1] == '=')
            {
                if (uf.connect(a, b + n) || uf.connect(b, a + n))
                    return false;
                // uf.unite(a, b);
                // uf.unite(a + n, b + n);
            }
            else
            {
                if (uf.connect(a, b) || uf.connect(a + n, b + n))
                    return false;
                uf.unite(a, b + n);
                uf.unite(b, a + n);
            }
        }
        return true;
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
    vector<string> a = {"a!=b", "b!=c", "c!=a"};
    solution.equationsPossible(a);
    return 0;
}