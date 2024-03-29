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
    bool dfs(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left && right)
        {
            return false;
        }
        if (left->val != right->val)
            return false;
        if (dfs(left->left, right->right))
        {
            return dfs(left->right, right->left);
        }
        return false;
    }
    bool bfs(TreeNode *left, TreeNode *right)
    {
        queue<TreeNode *> q;
        q.push(left);
        q.push(right);
        TreeNode *u1, *u2;
        while (q.size())
        {
            u1 = q.front();
            q.pop();
            u2 = q.front();
            q.pop();
            if (u1 == nullptr && u2 == nullptr)
                continue;
            if (!u1 && !u2)
                return false;
            if (u1->val != u2->val)
                return false;
            q.push(u1->left);
            q.push(u2->right);
            q.push(u1->right);
            q.push(u2->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode *root)
    {
        return bfs(root->left, root->right);
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

    return 0;
}