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
    int ans = 0, lower, upper;
    vector<long long> tmp;
    void merge_sort(vector<long long> &nums, int l, int r)
    {
        if (l >= r)
            return;
        int mid = l + ((r - l) >> 1);
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        mix(nums, l, mid, r);
    }

    void mix(vector<long long> &nums, int l, int mid, int r)
    {
        int i = l, j = mid + 1, k = l;
        int l0 = i, l1 = j, l2 = j;
        while (l0 <= mid)
        {
            while (l1 <= r && nums[l1] < nums[l0] + lower)
                l1++;
            // nums[l1] >= lower
            while (l2 <= r && nums[l2] <= nums[l0] + upper)
                l2++;
            // nums[l2] > upper
            ans += l2 - l1;
            l0++;
        }
        while (i <= mid && j <= r)
        {
            if (nums[i] <= nums[j])
                tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];
        }
        while (i <= mid)
            tmp[k++] = nums[i++];
        while (j <= r)
            tmp[k++] = nums[j++];
        for (int i = l; i <= r; ++i)
            nums[i] = tmp[i];
    }
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        this->lower = lower;
        this->upper = upper;
        vector<long long> sum(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            sum[i + 1] = sum[i] + nums[i];
        }
        n++;
        tmp.resize(n);
        merge_sort(sum, 0, n - 1);
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

    int l, r;
    cin >> l >> r;
    vector<int> a;
    while (cin >> k)
    {
        a.emplace_back(k);
    }
    cout << solution.countRangeSum(a, l, r) << endl;
    return 0;
}