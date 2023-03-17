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
    unordered_map<int, int> mp;
    int minSubarray(vector<int> &nums, int p)
    {
        int sum = 0;
        int ans = INF;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum = (sum + nums[i]) % p;
        }
        if (sum == 0)
            return 0;
        // r = sum
        int x2 = 0, x1;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            x2 = (x2 + nums[i]) % p;
            x1 = (x2 - sum + p) % p;
            if (mp.count(x1))
            {
                ans = min(ans, i - mp[x1]);
            }
            mp[x2] = i;
        }
        return ans == INF ? -1 : ans;
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
    read(n, k);
    for (int i = 0, x; i < n; ++i)
    {
        read(x);
        a.push_back(x);
    }
    cout << solution.minSubarray(a, k) << endl;
    return 0;
}