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

int init = []
{
    /*********** fast_read ***************/
    freopen("user.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*************************************/

    while (true)
    {
        if (!getline())
            break;

        getline();
    }
    exit(0);
    return 0;
}();

auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class SegTree
{
public:
    const static int maxn = 1e5 + 10;
    struct Node
    {
        int l, r, val;
        bool tag;
    } tree[maxn << 2];
    void build(int cur, int l, int r, vector<int> &nums)
    {
        tree[cur].l = l, tree[cur].r = r;
        tree[cur].tag = false;
        if (l == r)
        {
            tree[cur].val = nums[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(cur << 1, l, mid, nums);
        build(cur << 1 | 1, mid + 1, r, nums);
        tree[cur].val = tree[cur << 1].val + tree[cur << 1 | 1].val;
    }
    void pushdown(int cur)
    {
        tree[cur << 1].val = (tree[cur << 1].r - tree[cur << 1].l + 1) - tree[cur << 1].val;
        tree[cur << 1 | 1].val = (tree[cur << 1 | 1].r - tree[cur << 1 | 1].l + 1) - tree[cur << 1 | 1].val;
        tree[cur << 1].tag = !tree[cur << 1].tag;
        tree[cur << 1 | 1].tag = !tree[cur << 1 | 1].tag;
        tree[cur].tag = 0;
    }
    void update(int cur, int l, int r)
    {
        if (l <= tree[cur].l && r >= tree[cur].r)
        {
            // 对 cur node 取反，维护1的个数
            tree[cur].val = (tree[cur].r - tree[cur].l + 1) - tree[cur].val;
            tree[cur].tag = !tree[cur].tag;
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (tree[cur].tag)
            pushdown(cur);
        if (l <= mid)
            update(cur << 1, l, r);
        if (mid + 1 <= r)
            update(cur << 1 | 1, l, r);
        tree[cur].val = tree[cur << 1].val + tree[cur << 1 | 1].val;
    }
    int query(int cur, int l, int r)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
            return tree[cur].val;
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        int sum = 0;
        if (tree[cur].tag)
            pushdown(cur);
        // [l, mid]
        if (l <= mid)
            sum += query(cur << 1, l, r);
        // [mid + 1, r]
        if (mid + 1 <= r)
            sum += query(cur << 1 | 1, l, r);
        return sum;
    }
} segTree;
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        long long sum = 0;
        for (int i = 0; i < n2; ++i)
            sum += nums2[i];
        SegTree segTree;
        segTree.build(1, 0, n1 - 1, nums1);
        vector<long long> ans;
        for (auto &q : queries)
        {
            if (q[0] == 1)
                segTree.update(1, q[1], q[2]);
            else if (q[0] == 2)
                sum += (long long)segTree.query(1, 0, n1 - 1) * q[1];
            else
                ans.emplace_back(sum);
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
    vector<int> nums1 = {1}, nums2 = {5};
    vector<vector<int>> q = {{2, 0, 0}, {3, 0, 0}};
    solution.handleQuery(nums1, nums2, q);
    return 0;
}