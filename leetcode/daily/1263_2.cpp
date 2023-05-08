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
    const static int maxn = 4e2 + 10;
    int n, m;
    bool vis[maxn][maxn], vis_play[maxn];
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    bool dir[4];
    struct Node
    {
        int play_pos;
        int box_pos;
        int step;
        Node() {}
        Node(int play_pos, int box_pos, int step) : play_pos(play_pos), box_pos(box_pos), step(step) {}
    };
    int make_pos(pair<int, int> &pos) { return pos.first * m + pos.second; }
    pair<int, int> get_xy(int &pos) { return {pos / m, pos % m}; }
    void bfs_play(int play, int box, vector<vector<char>> &grid)
    {
        queue<int> q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                vis_play[i * m + j] = false;
        for (int i = 0; i < 4; ++i)
            dir[i] = false;
        q.push(play);
        vis_play[play] = true;
        pair<int, int> box_xy = get_xy(box);
        while (q.size())
        {
            auto out = q.front();
            q.pop();
            pair<int, int> out_xy = get_xy(out);
            if (out_xy.first == box_xy.first + 1 && out_xy.second == box_xy.second)
                dir[0] = true;
            else if (out_xy.first == box_xy.first && out_xy.second == box_xy.second - 1)
                dir[1] = true;
            else if (out_xy.first == box_xy.first - 1 && out_xy.second == box_xy.second)
                dir[2] = true;
            else if (out_xy.first == box_xy.first && out_xy.second == box_xy.second + 1)
                dir[3] = true;
            for (int i = 0; i < 4; ++i)
            {
                int newx = out_xy.first + dx[i];
                int newy = out_xy.second + dy[i];
                if (newx < 0 || newy < 0 || newx >= n || newy >= m || grid[newx][newy] == '#')
                    continue;
                int new_pos = newx * m + newy;
                if (new_pos == box || vis_play[new_pos])
                    continue;
                q.push(new_pos);
                vis_play[new_pos] = true;
            }
        }
    }
    int bfs_box(int play, int start, int end, vector<vector<char>> &grid)
    {
        queue<Node> q;
        vis[play][start] = true;
        q.push(Node(play, start, 0));
        while (q.size())
        {
            auto out = q.front();
            q.pop();
            if (out.box_pos == end)
                return out.step;
            pair<int, int> out_xy = get_xy(out.box_pos);
            bfs_play(out.play_pos, out.box_pos, grid);
            for (int i = 0; i < 4; ++i)
            {
                if (!dir[i])
                    continue;
                int newx = out_xy.first + dx[i];
                int newy = out_xy.second + dy[i];
                if (newx < 0 || newx >= n || newy < 0 || newy >= m || grid[newx][newy] == '#')
                    continue;
                int new_pos = newx * m + newy;
                if (vis[out.box_pos][new_pos])
                    continue;
                q.push(Node(out.box_pos, new_pos, out.step + 1));
                vis[out.box_pos][new_pos] = true;
            }
        }
        return -1;
    }
    int minPushBox(vector<vector<char>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        int start, end, play;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 'S')
                    play = i * m + j;
                else if (grid[i][j] == 'B')
                    start = i * m + j;
                else if (grid[i][j] == 'T')
                    end = i * m + j;
            }
        }
        return bfs_box(play, start, end, grid);
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