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
    // 二进制优化
    // 分别表示 行 列 九宫格
    enum
    {
        ROW,
        COL,
        GRID
    };
    bool dfs(int step, vector<vector<int>> &vis, vector<vector<char>> &board)
    {
        if (step == 81)
            return true;
        int row = step / 9, col = step % 9, grid = row / 3 * 3 + col / 3;
        if (board[row][col] != '.')
        {
            return dfs(step + 1, vis, board);
        }

        for (int i = 1; i <= 9; ++i)
        {
            if (vis[ROW][row] & (1 << i) ||
                vis[COL][col] & (1 << i) ||
                vis[GRID][grid] & (1 << i))
                continue;
            board[row][col] = i + '0';
            vis[ROW][row] |= (1 << i);
            vis[COL][col] |= (1 << i);
            vis[GRID][grid] |= (1 << i);
            if (dfs(step + 1, vis, board))
                return true;
            else
            {
                board[row][col] = '.';
                vis[ROW][row] &= ~(1 << i);
                vis[COL][col] &= ~(1 << i);
                vis[GRID][grid] &= ~(1 << i);
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> vis(3, vector<int>(9, 0));
        // 打标记
        for (int i = 0, num; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                num = board[i][j] - '0';
                vis[ROW][i] |= (1 << num);
                vis[COL][j] |= (1 << num);
                vis[GRID][i / 3 * 3 + j / 3] |= (1 << num);
            }
        }
        dfs(0, vis, board);
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
    vector<vector<char>> a;
    char x;
    for (int i = 0; i < 9; ++i)
    {
        vector<char> b;
        for (int j = 0; j < 9; ++j)
        {
            cin >> x;
            b.push_back(x);
        }
        a.push_back(b);
    }
    solution.solveSudoku(a);
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}