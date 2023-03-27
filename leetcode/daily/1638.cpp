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
    int countSubstrings(string s, string t)
    {
        int m = s.length(), n = t.length();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            if (s[i] == t[0])
                dp[i][0][0] = 1;
            else
            {
                dp[i][0][1] = 1;
                ans++;
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (s[0] == t[j])
                dp[0][j][0] = 1;
            else
            {
                dp[0][j][1] = 1;
                ans++;
            }
        }
        ans -= dp[0][0][1];
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (s[i] == t[j])
                {
                    dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
                    dp[i][j][1] = dp[i - 1][j - 1][1];
                }
                else
                {
                    dp[i][j][1] = dp[i - 1][j - 1][0] + 1;
                }
                ans += dp[i][j][1];
            }
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
    string s, t;
    cin >> s >> t; // 试试
    cout << solution.countSubstrings(s, t) << endl;
    return 0;
}