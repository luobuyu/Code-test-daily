// #pragma GCC optimize(2)
#include <bits/stdc++.h>
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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
string low, high;
int dp[maxn][40];
int len;
int dfs(int step, int diff, bool isUpperLimit, bool isLowerLimit, bool isLead)
{
    if (step == len)
    {
        return diff == 20;
    }
    if (!isUpperLimit && !isLowerLimit && !isLead && !dp[step][diff])
        return dp[step][diff];
    int ans = 0;
    if (isLead && low[step] == '0') // 只有存在前导零，low当前位是 0 才能填 0
        ans += dfs(step + 1, diff, false, true, true);
    int hi = (isUpperLimit ? high[step] - '0' : 9);
    int lo = (isLowerLimit ? low[step] - '0' : 0);
    for (int i = max(lo, isLead * 1); i <= hi; ++i)
    {
        ans += dfs(step + 1, diff + (i & 1 ? 1 : -1), isUpperLimit && i == hi, isLowerLimit && i == lo, false);
    }
    if (!isUpperLimit && !isLowerLimit && !isLead)
    {
        dp[step][diff] = ans;
    }
    return ans;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> low >> high;
    low = string(high.length() - low.length(), '0') + low;
    len = high.length();
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 20, true, true, true) << endl;
    return 0;
}