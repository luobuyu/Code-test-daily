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
    bool vis[maxn][maxn];
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
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
    int bfs(int play, int start, int end, vector<vector<char>> &grid)
    {
        deque<Node> q;
        q.push_back({play, start, 0});
        vis[play][start] = true;
        while (q.size())
        {
            auto out = q.front();
            q.pop_front();
            if (out.box_pos == end)
                return out.step;
            auto play_pos = get_xy(out.play_pos);
            auto box_pos = get_xy(out.box_pos);
            for (int i = 0; i < 4; ++i)
            {
                pair<int, int> new_play_pos = {play_pos.first + dx[i], play_pos.second + dy[i]};
                if (new_play_pos.first < 0 ||
                    new_play_pos.second < 0 ||
                    new_play_pos.first >= n ||
                    new_play_pos.second >= m ||
                    grid[new_play_pos.first][new_play_pos.second] == '#')
                    continue;
                if (new_play_pos == box_pos)
                {
                    pair<int, int> new_box_pos = {box_pos.first + dx[i], box_pos.second + dy[i]};
                    if (new_box_pos.first < 0 ||
                        new_box_pos.second < 0 ||
                        new_box_pos.first >= n ||
                        new_box_pos.second >= m ||
                        grid[new_box_pos.first][new_box_pos.second] == '#' ||
                        vis[make_pos(new_play_pos)][make_pos(new_box_pos)])
                        continue;
                    q.push_back(Node(make_pos(new_play_pos), make_pos(new_box_pos), out.step + 1));
                    vis[make_pos(new_play_pos)][make_pos(new_box_pos)] = true;
                }
                else
                {
                    if (vis[make_pos(new_play_pos)][out.box_pos])
                        continue;
                    q.push_front(Node(make_pos(new_play_pos), out.box_pos, out.step));
                    vis[make_pos(new_play_pos)][out.box_pos] = true;
                }
            }
            q.swap(q);
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
        return bfs(play, start, end, grid);
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