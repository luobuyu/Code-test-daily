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
    vector<vector<int>> ans;
    void dfs(int step, vector<int> &nums, vector<int> &cur, vector<bool> &vis)
    {
        if (step == nums.size())
        {
            ans.emplace_back(cur);
            return;
        }
        if (step > 0 && nums[step] == nums[step - 1] && !vis[step - 1])
        {
            dfs(step + 1, nums, cur, vis);
        }
        else
        {
            cur.emplace_back(nums[step]);
            vis[step] = true;
            dfs(step + 1, nums, cur, vis);
            vis[step] = false;
            cur.pop_back();
            dfs(step + 1, nums, cur, vis);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<bool> vis(nums.size(), false);
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(0, nums, cur, vis);
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
    vector<int> a;
    while (cin >> n)
    {
        a.push_back(n);
    }
    solution.subsetsWithDup(a);
    return 0;
}