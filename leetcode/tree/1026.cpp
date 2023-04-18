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
auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    const static int INF = 1e5 + 1;
    struct Node
    {
        int minx, maxx;
    };
    int ans = 0;
    Node dfs(TreeNode *u)
    {
        if (u == nullptr)
        {
            return {INF, -1};
        }
        Node left = dfs(u->left);
        Node right = dfs(u->right);
        Node tmp = {min(left.minx, right.minx), max(left.maxx, right.maxx)};
        if (tmp.minx != INF)
            ans = max(ans, abs(u->val - tmp.minx));
        if (tmp.maxx != -1)
            ans = max(ans, abs(u->val - tmp.maxx));
        // ans = max(ans, max(abs(u->val - tmp.minx), abs(u->val - tmp.maxx)))
        tmp.minx = min(tmp.minx, u->val);
        tmp.maxx = max(tmp.maxx, u->val);
        return tmp;
    }
    int maxAncestorDiff(TreeNode *root)
    {
        dfs(root);
        return ans;
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
    vector<int> a = {8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13};
    solution.maxAncestorDiff(build_tree(a));
    return 0;
}