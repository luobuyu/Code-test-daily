// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
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
    struct Node
    {
        int val;
        int id;
        int l, r;
        bool vis;
        bool operator<(const Node &p) const
        {
            return val < p.val;
        }
    };
    vector<Node> l;
    priority_queue<Node> q;
    void remove(Node &node)
    {
        l[node.id].vis = true;
        l[node.l].r = node.r;
        l[node.r].l = node.l;
    }
    int maxSizeSlices(vector<int> &slices)
    {
        int N = slices.size();
        int n = (N + 1) / 3;
        l.resize(N);
        for (int i = 0; i < N; ++i)
        {
            l[i].id = i;
            l[i].l = (i - 1 + N) % N;
            l[i].r = (i + 1) % N;
            l[i].val = slices[i];
            l[i].vis = false;
            q.push(l[i]);
        }
        int ans = 0;
        int cnt = 0;
        while (cnt < n)
        {
            auto out = q.top();
            q.pop();
            if (l[out.id].vis)
                continue;
            ans += l[out.id].val;
            cnt++;
            int left = l[out.id].l;
            int right = l[out.id].r;
            l[out.id].val = l[left].val + l[right].val - l[out.id].val;
            remove(l[left]);
            remove(l[right]);
            q.push(l[out.id]);
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
    vector<int> a = {1, 2, 3, 4, 5, 6};
    solution.maxSizeSlices(a);
    return 0;
}