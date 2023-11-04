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
long long mod = 1e9 + 7;
struct SegTree
{
    struct Node
    {
        int l, r;
        long long val1; // 平方和
        long long val2; // sum和
        int tag;
    };
    vector<Node> tree;
    // 4 倍空间
    SegTree(int n) : tree(n << 2) {}
    void build(int cur, int l, int r)
    {
        tree[cur].l = l, tree[cur].r = r, tree[cur].tag = 0;
        if (l == r)
        {
            tree[cur].val1 = 0;
            tree[cur].val2 = 0;
            return;
        }
        int mid = (l + r) >> 1;
        // [l, mid], [mid + 1, r]
        build(cur << 1, l, mid);
        build(cur << 1 | 1, mid + 1, r);
        tree[cur].val1 = tree[cur << 1].val1 + tree[cur << 1 | 1].val1;
        tree[cur].val2 = tree[cur << 1].val2 + tree[cur << 1 | 1].val2;
    }

    void add(int cur, int k)
    {
        int len = tree[cur].r - tree[cur].l + 1;
        tree[cur].val1 = (tree[cur].val1 + 2 * k * tree[cur].val2 % mod + k * k * len % mod) % mod;
        tree[cur].val2 = (tree[cur].val2 + k * len) % mod;
    }

    // void add(int cur, int l, int r, int k)
    // 区间 [l, r] 加 k
    void update(int cur, int l, int r, int k)
    {
        if (tree[cur].l >= l && tree[cur].r <= r)
        {
            add(cur, k);
            tree[cur].tag += k;
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        // 左侧 [tree[cur].l, mid], 右侧 [mid + 1, tree[cur].r]
        if (tree[cur].tag)
            pushdown(cur);
        if (l <= mid)
            update(cur << 1, l, r, k);
        if (mid + 1 <= r)
            update(cur << 1 | 1, l, r, k);
        tree[cur].val1 = (tree[cur << 1].val1 + tree[cur << 1 | 1].val1) % mod;
        tree[cur].val2 = (tree[cur << 1].val2 + tree[cur << 1 | 1].val2) % mod;
    }
    void pushdown(int cur)
    {
        tree[cur << 1].tag += tree[cur].tag;
        add(cur << 1, tree[cur].tag);
        tree[cur << 1 | 1].tag += tree[cur].tag;
        add(cur << 1 | 1, tree[cur].tag);
        tree[cur].tag = 0;
    }
    long long query(int cur, int l, int r)
    {
        if (tree[cur].l >= l && tree[cur].r <= r)
            return tree[cur].val1;
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        long long ret = 0;
        if (tree[cur].tag)
            pushdown(cur);
        if (l <= mid)
            ret += query(cur << 1, l, r);
        if (mid + 1 <= r)
            ret = (ret + query(cur << 1 | 1, l, r)) % mod;
        return ret;
    }
};

class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int sumCounts(vector<int> &nums)
    {
        int n = nums.size();
        long long mod = 1e9 + 7;
        long long sum = 1;
        vector<long long> dp(n);
        unordered_map<int, int> pre; // 存每个数前一个相同的位置
        SegTree segTree(n);
        segTree.build(1, 1, n);
        int p;
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!pre.count(nums[i]))
                p = 0;
            else
                p = pre[nums[i]] + 1;
            segTree.update(1, p + 1, i + 1, 1);
            // [1,i] 表示区间里面以 i 结尾的子数组的权值和。
            ans = (ans + segTree.query(1, 1, i + 1)) % mod;
            pre[nums[i]] = i;
        }
        return ans;
    }
};

int t,
    n,
    m,
    k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<int> a = {1, 2, 1};
    solution.sumCounts(a);
    return 0;
}