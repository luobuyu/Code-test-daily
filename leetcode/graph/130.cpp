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

    vector<int> fa;
    int find(int u)
    {
        return u == fa[u] ? u : fa[u] = find(fa[u]);
    }
    void unite(int u, int v)
    {
        int up = find(u);
        int vp = find(v);
        if (up != vp)
            fa[up] = vp;
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        int size = n * m + 1;
        fa.resize(size);
        for (int i = 0; i < size; ++i)
            fa[i] = i;
        int vir_root = size - 1;
        for (int i = 0; i < n; ++i)
        {
            if (board[i][0] == 'O')
                unite(i * m, vir_root);
            if (board[i][m - 1] == 'O')
                unite(i * m + m - 1, vir_root);
        }
        for (int i = 0; i < m; ++i)
        {
            if (board[0][i] == 'O')
                unite(i, vir_root);
            if (board[n - 1][i] == 'O')
                unite((n - 1) * m + i, vir_root);
        }

        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 1; j < m - 1; ++j)
            {
                if (board[i][j] != 'O')
                    continue;
                for (int k = 0; k < 4; ++k)
                {
                    int newx = i + dx[k];
                    int newy = j + dy[k];
                    if (board[newx][newy] != 'O')
                        continue;
                    unite(newx * m + newy, i * m + j);
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] != 'O')
                    continue;
                if (find(i * m + j) != find(vir_root))
                {
                    board[i][j] = 'X';
                }
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

    return 0;
}