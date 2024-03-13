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
        int val;
        int sum;
        int l, r;
    };
    vector<TreeNode> tree;
    SegTree(int n)
    {
        tree.resize((n + 1) << 2);
    }
    void build(int cur, int l, int r)
    {
        tree[cur].l = l, tree[cur].r = r;
        tree[cur].sum = 0;
        tree[cur].val = 0;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(cur << 1, l, mid);
        build(cur << 1 | 1, mid + 1, r);
    }
    void update(int cur, int index, int k)
    {
        if (tree[cur].l == tree[cur].r)
        {
            tree[cur].val += k;
            tree[cur].sum += k;
            return;
        }
        int mid = tree[cur].l + tree[cur].r >> 1;
        if (index <= mid)
            update(cur << 1, index, k);
        if (index >= mid + 1)
            update(cur << 1 | 1, index, k);
        tree[cur].sum = tree[cur << 1].sum + tree[cur << 1 | 1].sum;
    }
    int query(int cur, int l, int r)
    {
        if (l > r)
            return 0;
        if (l <= tree[cur].l && tree[cur].r <= r)
            return tree[cur].sum;
        int mid = tree[cur].l + tree[cur].r >> 1;
        int sum = 0;
        if (l <= mid)
            sum += query(cur << 1, l, r);
        if (mid + 1 <= r)
            sum += query(cur << 1 | 1, l, r);
        return sum;
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
    int size = 0;
    int hash(int num)
    {
        if (!mp.count(num))
            mp[num] = ++size;
        return mp[num];
    }
    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr1, arr2;
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        for (auto &x : tmp)
            hash(x);
        SegTree seg1(size), seg2(size);
        seg1.build(1, 1, size);
        seg2.build(1, 1, size);
        arr1.emplace_back(nums[0]);
        seg1.update(1, hash(nums[0]), 1);
        arr2.emplace_back(nums[1]);
        seg2.update(1, hash(nums[1]), 1);
        for (int i = 2; i < n; ++i)
        {
            int p = hash(nums[i]);
            int cnt1 = seg1.query(1, p + 1, size);
            int cnt2 = seg2.query(1, p + 1, size);
            if (cnt1 > cnt2)
            {
                arr1.emplace_back(nums[i]);
                seg1.update(1, p, 1);
            }
            else if (cnt1 < cnt2)
            {
                arr2.emplace_back(nums[i]);
                seg2.update(1, p, 1);
            }
            else
            {
                if (arr1.size() <= arr2.size())
                {
                    arr1.emplace_back(nums[i]);
                    seg1.update(1, p, 1);
                }
                else
                {
                    arr2.emplace_back(nums[i]);
                    seg2.update(1, p, 1);
                }
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
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
    vector<int> a = {2, 1, 3, 3};
    solution.resultArray(a);
    return 0;
}