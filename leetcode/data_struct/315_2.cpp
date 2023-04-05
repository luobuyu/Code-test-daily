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
    vector<pair<int, int>> tmp; // value, index
    vector<pair<int, int>> nums_p;
    void mix_merge(vector<int> &ans, vector<pair<int, int>> &nums, int l, int mid, int r)
    {
        // [l, mid], [mid + 1, r]
        int l1 = l, l2 = mid + 1, l3 = l;
        while (l1 <= mid && l2 <= r)
        {
            if (nums[l1].first <= nums[l2].first)
            {
                ans[nums[l1].second] += l2 - mid - 1;
                tmp[l3++] = nums[l1++];
            }
            else
            {
                tmp[l3++] = nums[l2++];
            }
        }
        while (l1 <= mid)
        {
            ans[nums[l1].second] += l2 - mid - 1;
            tmp[l3++] = nums[l1++];
        }
        while (l2 <= r)
            tmp[l3++] = nums[l2++];
        for (int i = l; i <= r; ++i)
        {
            nums[i] = tmp[i];
        }
    }

    void merge_sort(vector<int> &ans, vector<pair<int, int>> &nums, int l, int r)
    {
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        merge_sort(ans, nums, l, mid);
        merge_sort(ans, nums, mid + 1, r);
        mix_merge(ans, nums, l, mid, r);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        tmp.resize(n);
        nums_p.resize(n);
        for (int i = 0; i < n; ++i)
        {
            nums_p[i] = {nums[i], i};
        }
        vector<int> ans(n);
        merge_sort(ans, nums_p, 0, n - 1);
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
    vector<int> a;
    while (cin >> n)
    {
        a.emplace_back(n);
    }
    solution.countSmaller(a);
    return 0;
}