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
    bool dfs(int step, int cur, int len, vector<int> &nums, int mask, int cnt)
    {
        if (cnt == 3)
            return true;
        for (int i = step; i < nums.size(); ++i)
        {
            if (mask & (1 << i))
                continue;
            if (cur + nums[i] <= len)
            {
                if (dfs(i + 1, cur + nums[i], len, nums, mask | (1 << i), cnt + (cur + nums[i] == len)))
                {
                    return true;
                }
                // 放置失败
                if (cur == 0 || cur + nums[i] == len)
                    return false;
            }
            while (nums[i + 1] == nums[i])
                i++;
        }
        return false;
    }
    bool makesquare(vector<int> &matchsticks)
    {
        int sum = 0;
        vector<int> cur(4);
        for (int i = 0; i < matchsticks.size(); ++i)
        {
            sum += matchsticks[i];
        }
        if (sum % 4)
            return false;
        int len = sum / 4;
        for (int i = 0; i < matchsticks.size(); ++i)
        {
            if (matchsticks[i] > len)
                return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(0, 0, len, matchsticks, 0, 0);
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
    int x;
    while (cin >> x)
    {
        a.emplace_back(x);
    }
    cout << solution.makesquare(a) << endl;
    return 0;
}