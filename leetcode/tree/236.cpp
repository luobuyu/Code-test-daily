// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
int t, n, m, k;
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;
    unordered_map<TreeNode *, unordered_map<int, TreeNode *>> fa;
    unordered_map<TreeNode *, int> depth;
    void dfs(TreeNode *root, TreeNode *p, int dep)
    {

        if (root == nullptr)
            return;
        if (root->val == 5)
        {
            cout << p << endl;
        }
        fa[root][0] = p;
        depth[root] = dep;
        dfs(root->left, root, dep + 1);
        dfs(root->right, root, dep + 1);
    }

    void build()
    {
        for (int k = 1; k < 17; ++k)
        {
            for (auto &root : depth)
            {
                fa[root.first][k] = fa[fa[root.first][k - 1]][k - 1];
            }
        }
    }

    TreeNode *query(TreeNode *p, TreeNode *q)
    {
        if (depth[p] < depth[q])
            swap(p, q);
        int tmp = depth[p] - depth[q];
        for (int i = 17; i >= 0; --i)
        {
            if (tmp >= (1 << i))
            {
                p = fa[p][i];
            }
        }
        if (p == q)
            return p;
        for (int i = 17; i >= 0; --i)
        {
            if (depth[p] >= (1 << i))
            {
                if (fa[p][i] != fa[q][i])
                {
                    p = fa[p][i];
                    q = fa[q][i];
                }
            }
        }
        return fa[p][0];
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, nullptr, 0);
        cout << depth[p] << endl;
        build();
        return query(p, q);
    }
};

TreeNode *search(TreeNode *root, int val)
{
    if (root == nullptr)
        return nullptr;
    if (root->val == val)
        return root;
    TreeNode *left = search(root->left, val);
    search(root->right, val);
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<int> a;
    while (cin >> k)
    {
        a.emplace_back(k);
    }
    TreeNode *root = build_tree(a);

    TreeNode *p = search(root, 5);
    TreeNode *q = search(root, 1);
    solution.lowestCommonAncestor(build_tree(a), p, q);
    return 0;
}