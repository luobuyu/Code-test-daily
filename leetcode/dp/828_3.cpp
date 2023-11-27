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
        int sum;
        int lazy;
    };
    vector<TreeNode> tree;
    SegTree(int n) : tree(n << 2) {}
    void build(int cur, int l, int r)
    {
        tree[cur].l = l, tree[cur].r = r;
        tree[cur].sum = tree[cur].lazy = 0;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(cur << 1, l, mid);
        build(cur << 1 | 1, mid + 1, r);
    }
    void update(int cur, int l, int r, int k)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
        {
            tree[cur].lazy += k;
            tree[cur].sum += k * (tree[cur].r - tree[cur].l + 1);
            return;
        }
        if (tree[cur].lazy)
            pushdown(cur);
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (l <= mid)
            update(cur << 1, l, r, k);
        if (mid + 1 <= r)
            update(cur << 1 | 1, l, r, k);
        tree[cur].sum = tree[cur << 1].sum + tree[cur << 1 | 1].sum;
    }

    void pushdown(int cur)
    {
        tree[cur << 1].lazy += tree[cur].lazy;
        tree[cur << 1].sum += (tree[cur << 1].r - tree[cur << 1].l + 1) * tree[cur].lazy;
        tree[cur << 1 | 1].lazy += tree[cur].lazy;
        tree[cur << 1 | 1].sum += (tree[cur << 1 | 1].r - tree[cur << 1 | 1].l + 1) * tree[cur].lazy;
        tree[cur].lazy = 0;
    }

    int query(int cur, int l, int r)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
            return tree[cur].sum;
        if (tree[cur].lazy)
            pushdown(cur);
        int mid = (tree[cur].l + tree[cur].r) >> 1;
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
    const int INF = 0x3f3f3f3f;
    int uniqueLetterString(string s)
    {
        int n = s.length();
        unordered_map<char, int> pre1, pre2;
        // dp[i] = [0, i] 价值
        // dp[i] = dp[i - 1] + sum(0, pre) +
        // AB 1 + 1 + 2 = 4
        // AB C = 4 + 3(ABC) + 2(BC) + 1(C) = 10

        // AB 4
        // AB A = 4 + 1(ABA) + 2(BA) + 1(A) = 8
        // AB
        // 1 + 2 + 1 = 4
        // A B A
        // 1 + (1+1 1)
        // A B A
        // 4 + (1+1 1+1 1)
        // ABCAA

        // 下标从 1 开始
        // L
        // 1
        // L E
        // 1 +( 2 1 ) = 4
        // L E E
        // 4 + (2-1 1-1 + 1)
        // 4 + (1 0 1) = 6
        // L E E E
        // 6 + (1 0 1-1 1)

        long long cur = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (pre1.count(s[i]))
            {
                cur += i + 1 - (pre1[s[i]] + 1 + 1);
                if (pre2.count(s[i]))
                    cur -= pre1[s[i]] + 1 - (pre2[s[i]] + 1 + 1);
                else
                    cur -= pre1[s[i]] + 1;
            }
            else
                cur += i + 1;
            sum += cur;
            cout << sum << endl;
            if (!pre1.count(s[i]))
                pre1[s[i]] = i;
            else
            {
                pre2[s[i]] = pre1[s[i]];
                pre1[s[i]] = i;
            }
        }
        return sum;
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