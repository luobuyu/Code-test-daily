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
struct SegTree
{
    struct TreeNode
    {
        int l, r, val;
    };
    vector<TreeNode> tree;
    SegTree(int n) : tree(n << 2) {}
    void build(int cur, int l, int r, vector<int> &heights)
    {
        tree[cur].l = l, tree[cur].r = r, tree[cur].val = 0;
        if (l == r)
        {
            tree[cur].val = heights[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(cur << 1, l, mid, heights);
        build(cur << 1 | 1, mid + 1, r, heights);
        tree[cur].val = max(tree[cur << 1].val, tree[cur << 1 | 1].val);
    }
    int query(int cur, int l, int r, int limit)
    {
        if (tree[cur].val <= limit)
            return -1;
        if (tree[cur].l == tree[cur].r)
            return tree[cur].l;
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (l <= mid)
        {
            int pos = query(cur << 1, l, r, limit);
            if (pos != -1)
                return pos;
        }
        if (mid + 1 <= r)
            return query(cur << 1 | 1, l, r, limit);
    }
};
class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
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
    vector<int> a = {6, 4, 8, 5, 2, 7};
    vector<vector<int>> b = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
    solution.leftmostBuildingQueries(a, b);
    return 0;
}