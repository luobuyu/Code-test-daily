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
        int l, r;
        int val;
        int lazy;
    };
    vector<TreeNode> tree;
    SegTree(int n) : tree(n << 2) {}
    void build(int cur, int l, int r, vector<int> &nums)
    {
        tree[cur].l = l, tree[cur].r = r, tree[cur].lazy = 0;
        if (l == r)
        {
            tree[cur].val = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(cur << 1, l, mid, nums);
        build(cur << 1 | 1, mid + 1, r, nums);
        tree[cur].val = tree[cur << 1].val + tree[cur << 1 | 1].val;
    }
    void update(int cur, int index, int val)
    {
        if (tree[cur].l == index && tree[cur].r == index)
        {
            tree[cur].val = val;
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (index <= mid)
            update(cur << 1, index, val);
        if (index >= mid + 1)
            update(cur << 1 | 1, index, val);
        tree[cur].val = tree[cur << 1].val + tree[cur << 1 | 1].val;
    }
    int query(int cur, int l, int r)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
        {
            return tree[cur].val;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        int sum = 0;
        if (l <= mid)
            sum += query(cur << 1, l, r);
        if (mid + 1 <= r)
            sum += query(cur << 1 | 1, l, r);
        return sum;
    }
};
class NumArray
{
public:
    SegTree segTree;
    NumArray(vector<int> &nums) : segTree(nums.size())
    {
        segTree.build(1, 1, nums.size(), nums);
    }

    void update(int index, int val)
    {
        segTree.update(1, index + 1, val);
    }

    int sumRange(int left, int right)
    {
        return segTree.query(1, left + 1, right + 1);
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
    vector<int> a = {0, 9, 5, 7, 3};
    NumArray solution(a);
    cout << solution.sumRange(4, 4) << endl;
    return 0;
}