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
    int dp[31][31] = {};
    int mergeStones(vector<int> &stones, int k)
    {
        int n = stones.size();
        if (n < k || (n - 1) % (k - 1))
            return -1;
        vector<int> sum(n, 0);
        sum[0] = stones[0];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i < n; ++i)
        {
            sum[i] = sum[i - 1] + stones[i];
            dp[i][i] = 0;
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                for (int p = i; p < j; p += k - 1)
                {
                    dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j] + (!((len - 1) % (k - 1))) * (sum[j] - (i - 1 >= 0 ? sum[i - 1] : 0)));
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
    read(n, k);
    vector<int> a;
    for (int i = 0, x; i < n; ++i)
    {
        read(x);
        a.emplace_back(x);
    }
    cout << solution.mergeStones(a, k) << endl;
    return 0;
}