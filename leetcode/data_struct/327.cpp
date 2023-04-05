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
    struct Tree
    {
        vector<int> c;
        int max_size;
        Tree(int n) : c(n + 1), max_size(n) {}
        int lowbit(int x) { return x & -x; }
        void add(int index, int value)
        {
            while (index <= max_size)
            {
                c[index] += value;
                index += lowbit(index);
            }
        }
        int query(int index)
        {
            int ans = 0;
            while (index >= 1)
            {
                ans += c[index];
                index -= lowbit(index);
            }
            return ans;
        }
    };
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        vector<int> sum(n, 0);
        int tmp = 0;
        for (int i = 0; i < n; ++i)
        {
            tmp += nums[i];
            sum[i] = tmp;
        }
        // 需要统计 sum[i] 有多少个
        // [1, max_sum]
        // 离散化，需要和 lower, upper一起离散化？
        // 查询[1, sum[i] + upper] [1, sum[i] - upper]
        // [1, sum[i] - lower] [1, sum[i] + lower]
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

    int l, r;
    cin >> l >> r;
    vector<int> a;
    while (cin >> k)
    {
    }
    return 0;
}