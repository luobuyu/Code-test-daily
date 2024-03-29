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
    vector<vector<int>> dp;
    int numDupDigitsAtMostN(int n)
    {
        string s = to_string(n);
        dp.resize(s.size(), vector<int>(1 << 10, 0));
        return n - dfs(0, s, true, 0) + 1;
    }

    int dfs(int step, string &s, bool isPreUpper, int mask)
    {
        if (step == s.size())
        {
            return 1;
        }
        if (!isPreUpper && dp[step][mask])
        {
            return dp[step][mask];
        }
        int ans = 0;
        int upper = isPreUpper ? (s[step] - '0') : 9;
        for (int i = 0; i <= upper; ++i)
        {
            if (mask & (1 << i))
                continue;
            int new_mask = mask;
            if (mask == 0 && i == 0)
                new_mask = 0;
            else
                new_mask = mask | (1 << i);

            ans += dfs(step + 1, s, isPreUpper && i == upper, new_mask);
        }
        if (!isPreUpper)
        {
            dp[step][mask] = ans;
        }
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
    cin >> n;
    cout << solution.numDupDigitsAtMostN(n) << endl;
    return 0;
}