// #pragma GCC optimize(2)
#include <bits/stdc++.h>
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
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
class Solution
{
public:
    vector<int> preSum;
    int n;
    vector<int> decrypt(vector<int> &code, int k)
    {
        n = code.size();
        preSum.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            preSum[i] = preSum[i - 1] + code[i - 1];
        }
        vector<int> ans(n, 0);
        if (k > 0)
        {
            for (int i = 1; i <= n; ++i)
            {
                ans[i - 1] = getSum(i + 1, i + k);
            }
        }
        else if (k < 0)
        {
            for (int i = 1; i <= n; ++i)
            {
                ans[i - 1] = getSum(i + k, i - 1);
            }
        }
        return ans;
    }
    // [l, r]
    int getSum(int l, int r)
    {
        l = ((l - 1) % n + n) % n + 1;
        r = ((r - 1) % n + n) % n + 1;
        if (r >= l)
            return preSum[r] - preSum[l - 1];
        else
            return preSum[r] - preSum[l - 1] + preSum[n];
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
    vector<int> a = {10, 5, 7, 7, 3, 2, 10, 3, 6, 9, 1, 6};
    Solution solution;
    solution.decrypt(a, -4);
    return 0;
}