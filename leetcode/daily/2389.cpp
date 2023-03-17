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
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        int tmp = 0;
        for (int i = 0; i < n; ++i)
        {
            tmp += nums[i];
            nums[i] = tmp;
        }
        vector<int> ret(m);
        int l, r, mid;
        for (int i = 0, index; i < m; ++i)
        {
            // index = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            l = 0, r = n - 1;
            while (l != r)
            {
                mid = (l + r) >> 1;
                if (nums[mid] <= queries[i])
                {
                    index = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            if (index == 0)
                ret[i] = 0;
            else
                ret[i] = index;
        }
        return ret;
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