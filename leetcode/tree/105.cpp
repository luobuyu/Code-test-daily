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
    // 前序，中序
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int l1, int r1, int l2, int r2)
    {
        TreeNode *cur = new TreeNode;
        if (l1 > r1)
            return nullptr;
        cur->val = preorder[l1];
        int i;
        for (i = l2; i <= r2; ++i)
        {
            if (cur->val == inorder[i])
                break;
        }
        int size = i - l2;
        cur->left = build(preorder, inorder, l1 + 1, l1 + size, l2, i - 1);
        cur->right = build(preorder, inorder, l1 + size + 1, r1, i + 1, r2);
        return cur;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    cin >> n;
    vector<int> pre(n), in(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> in[i];
    }
    solution.buildTree(pre, in);
    return 0;
}