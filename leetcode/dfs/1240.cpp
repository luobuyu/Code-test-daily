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
    const static int maxn = 1e1 + 10;
    const static int maxm = 1e1 + 10;
    const int INF = 0x3f3f3f3f;
    int flag[maxn] = {};
    int ans = INF;
    int tilingRectangle(int n, int m)
    {
        dfs(0, 0, 0, n, m);
        return ans;
    }
    void dfs(int cnt, int x, int y, int &n, int &m)
    {
        if (cnt >= ans)
            return;
        if (x >= n)
        {
            ans = cnt;
            return;
        }
        if (y >= m)
        {
            dfs(cnt, x + 1, 0, n, m);
        }
        else
        {
            if ((flag[x] >> y) & 1)
            {
                dfs(cnt, x, y + 1, n, m);
            }
            else
            {
                for (int width = min(m - y, n - x); width >= 1 && check(x, y, width); --width)
                {
                    mark(x, y, width);
                    dfs(cnt + 1, x, y + width, n, m);
                    mark(x, y, width);
                }
            }
        }
    }
    bool check(int x, int y, int width)
    {
        for (int i = 0; i < width; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if ((flag[x + i] >> (y + j)) & 1)
                    return false;
            }
        }
        return true;
    }

    void mark(int x, int y, int width)
    {
        for (int i = 0; i < width; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                flag[x + i] ^= (1 << (y + j));
            }
        }
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
    solution.tilingRectangle(2, 3);
    return 0;
}