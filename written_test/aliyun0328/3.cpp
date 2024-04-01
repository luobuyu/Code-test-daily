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
int len;
int dp[maxn];
string high, low;
unordered_set<int> s;
int dfs(int step, int val, bool isUpper, bool isLower, bool isLead)
{
    if (step == len)
        return isLead ? 0 : val;
    if (!isUpper && !isLower && !isLead && dp[step] != -1)
        return dp[step];
    int ans = 0;
    if (isLead && low[step] == '0') // 下界当前为0才能填0，否则最少填下界。
        ans = max(ans, dfs(step + 1, val, false, true, true));
    int lo = isLower ? low[step] - '0' : 0;
    int hi = isUpper ? high[step] - '0' : 9;

    for (int i = max(lo, (int)isLead); i <= hi; ++i)
    {
        if (s.count(i))
            ans = max(ans, dfs(step + 1, val + 1, isUpper && i == hi, isLower && i == lo, false));
        else
            ans = max(ans, dfs(step + 1, val, isUpper && i == hi, isLower && i == lo, false));
    }
    if (!isUpper && !isLower && !isLead)
        dp[step] = ans;
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
    int tcase;
    read(tcase);
    while (tcase--)
    {
    }
    return 0;
}