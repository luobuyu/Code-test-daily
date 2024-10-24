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
    // dp[i][j] = dp[i][k] + dp[k][j] + v[i] * v[k] * v[j];
    vector<vector<int>> dp;
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        dp.resize(n, vector<int>(n));
        // i,j 需要知道 i,k 与 k,j;
        // 因此 j 正着枚举，i 倒着枚举
        for (int i = n - 3; i >= 0; --i)
        {
            for (int j = i + 2; j < n; ++j)
            {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k)
                {
                    dp[i][j] = min(dp[i][k] + dp[k][j] + values[i] * values[k] * values[j], dp[i][j]);
                }
            }
        }
        return dp[0][n - 1];
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
    while (cin >> k)
    {
        a.emplace_back(k);
    }
    solution.minScoreTriangulation(a);
    return 0;
}