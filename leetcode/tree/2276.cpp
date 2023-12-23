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
        TreeNode *left;
        TreeNode *right;
        int l, r, cnt;
        TreeNode(int _l, int _r) : l(_l), r(_r), left(nullptr), right(nullptr), cnt(0) {}
    };
    TreeNode *root;
    SegTree(int l, int r) { root = new TreeNode(l, r); }
    void add(TreeNode *cur, int l, int r)
    {
        if (l <= cur->l && cur->r <= r)
        {
            cur->cnt = cur->r - cur->l + 1;
            return;
        }
        // 防止越界
        int mid = cur->l + ((cur->r - cur->l) >> 1);
        int sum = 0;
        if (l <= mid)
        {
            if (cur->left == nullptr)
                cur->left = new TreeNode(cur->l, mid);
            add(cur->left, l, r);
        }
        if (mid + 1 <= r)
        {
            if (cur->right == nullptr)
                cur->right = new TreeNode(mid + 1, cur->r);
            add(cur->right, l, r);
        }

        if (cur->left)
            sum += cur->left->cnt;
        if (cur->right)
            sum += cur->right->cnt;
        cur->cnt = sum;
    }
    int query(TreeNode *cur, int l, int r)
    {
        if (cur == nullptr)
            return 0;
        if (l <= cur->l && cur->r <= r)
            return cur->cnt;
        int mid = cur->l + ((cur->r - cur->l) >> 1);
        int sum = 0;
        if (l <= mid)
            sum += query(cur->left, l, r);
        if (mid + 1 <= r)
            sum += query(cur->right, l, r);
        return sum;
    }
};
class CountIntervals
{
public:
    SegTree seg;
    CountIntervals() : seg(1, 10)
    {
    }

    void add(int left, int right)
    {
        seg.add(seg.root, left, right);
    }

    int count()
    {
        return seg.query(seg.root, 1, 10);
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
    CountIntervals solution;
    solution.add(2, 3);
    cout << solution.count() << endl;
    solution.add(7, 10);
    cout << solution.count() << endl;
    return 0;
}