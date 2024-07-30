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

// 需要维护区间最值
struct SegTree
{
    struct TreeNode
    {
        int l, r;
        int val;
        int tag;
    };
    vector<TreeNode> tree;

    SegTree(int n) : tree(n << 2) {}

    void build(int cur, int l, int r)
    {
        tree[cur].l = l;
        tree[cur].r = r;
        tree[cur].val = tree[cur].tag = 0;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(cur << 1, l, mid);
        build(cur << 1 | 1, mid + 1, r);
        tree[cur].val = max(tree[cur << 1].val, tree[cur << 1 | 1].val);
    }

    void update(int cur, int l, int r, int k)
    {
        // if(tree[cur].r < l || tree[cur].l > r)
        //     return;
        if (l <= tree[cur].l && tree[cur].r <= r)
        {
            tree[cur].val = k;
            tree[cur].tag = k;
            return;
        }
        if (tree[cur].tag)
            pushdown(cur);
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (l <= mid)
            update(cur << 1, l, r, k);
        if (mid + 1 <= r)
            update(cur << 1 | 1, l, r, k);
        tree[cur].val = max(tree[cur << 1].val, tree[cur << 1 | 1].val);
    }
    void pushdown(int cur)
    {
        tree[cur << 1].tag = tree[cur].tag;
        tree[cur << 1].val = tree[cur].tag;
        tree[cur << 1 | 1].tag = tree[cur].tag;
        tree[cur << 1 | 1].val = tree[cur].tag;
        tree[cur].tag = 0;
    }

    int query(int cur, int l, int r)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
        {
            return tree[cur].val;
        }
        if (tree[cur].tag)
            pushdown(cur);
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        int ans = 0;
        if (l <= mid)
            ans = max(ans, query(cur << 1, l, r));
        if (mid + 1 <= r)
            ans = max(ans, query(cur << 1 | 1, l, r));
        return ans;
    }
};

class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    unordered_map<int, int> mp;
    int tot = 1;
    int getMapX(int x)
    {
        if (!mp.count(x))
            mp[x] = tot++;
        return mp[x];
    }
    vector<int> fallingSquares(vector<vector<int>> &positions)
    {
        int n = positions.size();
        vector<int> tmpx;
        for (auto &pos : positions)
        {
            pos[1] += pos[0];
            tmpx.emplace_back(pos[0]);
            tmpx.emplace_back(pos[1]);
        }
        sort(tmpx.begin(), tmpx.end());
        for (auto &x : tmpx)
        {
            getMapX(x);
        }

        vector<int> ans(n);
        SegTree segTree(tot);
        segTree.build(1, 1, tot);
        for (int i = 0; i < n; ++i)
        {
            auto &pos = positions[i];
            int x = getMapX(pos[0]);
            int y = getMapX(pos[1]);
            int width = pos[1] - pos[0];
            int maxx = segTree.query(1, x, y - 1);
            segTree.update(1, x, y - 1, width + maxx);
            ans[i] = segTree.query(1, 1, tot);
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
    vector<vector<int>> a = {{9, 7}, {1, 9}, {3, 1}};
    solution.fallingSquares(a);
    return 0;
}