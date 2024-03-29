// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{
    static string buf_line;
    static int _i;
    static int _n;
    static char _ch;
    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        _ch = buf_line[_i++];
        while (_ch < '0' || _ch > '9')
        {
            if (_ch == '-')
                flag = -1;
            _ch = buf_line[_i++];
        }
        while (_ch >= '0' && _ch <= '9')
        {
            x = (x << 3) + (x << 1) + (_ch ^ 48), _ch = buf_line[_i++];
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

    bool endofl()
    {
        if (_i >= _n)
            return true;
        if (_i == 0)
            return false;
        if (buf_line[_i - 1] == ']')
        {
            _i++;
            return true;
        }
        return false;
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

// int init = []
// {
//     /*********** fast_read ***************/
//     freopen("user.out", "w", stdout);
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     /*************************************/

//     while (true)
//     {
//         if (!getline())
//             break;

//         getline();
//     }
//     exit(0);
//     return 0;
// }();

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
    int slidingPuzzle(vector<vector<int>> &board)
    {
        int n = board.size(), m = board[0].size();
        int sx, sy;
        string s;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == 0)
                {
                    sx = i, sy = j;
                }
                s += board[i][j] + '0';
            }
        }
        unordered_map<string, pair<int, int>> vis;
        string target = "123450";
        queue<string> q;
        q.push(s);
        vis[s] = {sx, sy};
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
        int ans = 0;
        while (q.size())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                auto s = q.front();
                q.pop();
                if (s == target)
                    return ans;
                int x = vis[s].first, y = vis[s].second;
                for (int i = 0; i < 4; ++i)
                {
                    int newx = x + dx[i], newy = y + dy[i];
                    if (newx < 0 || newx >= n || newy < 0 || newy >= m)
                        continue;
                    int old_index = x * 3 + y;
                    int new_index = newx * 3 + newy;
                    auto tmp = s;
                    swap(tmp[old_index], tmp[new_index]);
                    if (vis.count(tmp))
                        continue;
                    vis[tmp] = {newx, newy};
                }
            }
            ans++;
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
    vector<vector<int>> a = {{1, 2, 3}, {4, 0, 5}};
    solution.slidingPuzzle(a);
    return 0;
}