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
// 双向bfs
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int oneTurn(queue<string> &q, int ans, unordered_set<string> &vis1, unordered_set<string> &vis2, unordered_set<string> &mp)
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            auto s = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 2; ++j)
                {
                    auto tmp = s;
                    int add = (j == 0 ? -1 : 1);
                    tmp[i] = (tmp[i] - '0' + 10 + add) % 10 + '0';
                    if (mp.count(tmp) || vis1.count(tmp))
                        continue;
                    if (vis2.count(tmp))
                        return ans + 1;
                    vis1.insert(tmp);
                    q.push(tmp);
                }
            }
            ans++;
        }
        return -1;
    }
    int openLock(vector<string> &deadends, string target)
    {
        string cur = "0000";
        queue<string> q1, q2;
        unordered_set<string> mp;
        unordered_set<string> vis1, vis2;
        for (auto &deadend : deadends)
        {
            if (deadend == target || deadend == cur)
                return -1;
            mp.insert(deadend);
        }
        if (cur == target)
            return 0;
        q1.push(cur);
        vis1.insert(cur);
        q2.push(target);
        vis2.insert(target);
        int ans = 0, tmp;
        while (q1.size() && q2.size())
        {
            if (q1.size() < q2.size())
            {
                tmp = oneTurn(q1, ans, vis1, vis2, mp);
            }
            else
            {
                tmp = oneTurn(q2, ans, vis2, vis1, mp);
            }
            if (tmp != -1)
                return tmp;
            ans++;
        }
        return -1;
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