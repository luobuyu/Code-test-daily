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
    const static int maxn = 1e0 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;
    int dp[maxn][maxn] = {};
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    if (dp[i][j - 1] > dp[i - 1][j])
                    {
                        dp[i][j] = dp[i][j - 1];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        string ans;
        int l1 = n, l2 = m;
        while (l1 && l2)
        {
            if (str1[l1 - 1] == str2[l2 - 1])
            {
                ans = str1[l1 - 1] + ans;
                l1--;
                l2--;
            }
            else
            {
                if (dp[l1][l2] == dp[l1][l2 - 1])
                {
                    ans = str2[l2 - 1] + ans;
                    l2--;
                }
                else
                {
                    ans = str1[l1 - 1] + ans;
                    l1--;
                }
            }
        }
        if (l1)
            ans = str1.substr(0, l1) + ans;
        if (l2)
            ans = str2.substr(0, l2) + ans;
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
    string s1, s2;
    cin >> s1 >> s2;
    cout << solution.shortestCommonSupersequence(s1, s2) << endl;
    return 0;
}