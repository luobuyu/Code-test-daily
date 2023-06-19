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
    std::cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    static const int maxn = 1e5 + 10;
    int dp[maxn] = {};
    int need[maxn] = {};
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k)
    {
        for (auto &edge : relations)
        {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            need[(1 << v)] |= (1 << u);
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i < (1 << n); ++i)
        {
            int set1 = i & (-i);
            int set2 = i ^ set1;
            need[i] = need[set1] | need[set2];
            if ((need[i] | i) != i)
                continue;

            int valid = i ^ need[i];
            if (__builtin_popcount(valid) <= k)
            {
                dp[i] = min(dp[i], dp[i ^ valid] + 1);
            }
            else
            {
                for (int sub = valid; sub; sub = valid & (sub - 1))
                {
                    if (__builtin_popcount(sub) <= k)
                    {
                        dp[i] = min(dp[i], dp[i ^ sub] + 1);
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
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