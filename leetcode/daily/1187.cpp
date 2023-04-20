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
    const static int maxn = 2e3 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;
    int dp[maxn][maxn]; // dp[i][j]表示arr1前i位与arr2前j位得到最小的末尾数字（升序）
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int n = arr1.size(), m = arr2.size();
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = -1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= min(n, m); ++j)
            {
                if (arr1[i - 1] > dp[i - 1][j])
                {
                    dp[i][j] = min(dp[i][j], arr1[i - 1]);
                }
                if (j > 0)
                {
                    int tmp = upper_bound(arr2.begin() + j - 1, arr2.end(), dp[i - 1][j - 1]) - arr2.begin();
                    if (tmp != m)
                        dp[i][j] = min(dp[i][j], arr2[tmp]);
                }
            }
        }
        int ans = -1;
        for (int j = 0; j <= min(n, m); ++j)
        {
            if (dp[n][j] != INF)
            {
                ans = j;
                break;
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
    vector<int> a1 = {31, 18, 1, 12, 23, 14, 25, 4, 17, 18, 29, 28, 35, 34, 19, 8, 25, 6, 35};
    vector<int> a2 = {13, 10, 25, 18, 3, 8, 37, 20, 23, 12, 9, 36, 17, 22, 29, 6, 1, 12, 37, 6, 3, 14, 37, 2};
    cout << solution.makeArrayIncreasing(a1, a2) << endl;
    return 0;
}