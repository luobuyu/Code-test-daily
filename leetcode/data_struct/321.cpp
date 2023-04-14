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
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;
    // 从 num 中取出 k 个数，最大
    void getSeq(vector<int> &num, int k, vector<int> &st)
    {
        int top = -1, remain = num.size();
        for (int i = 0; i < num.size(); ++i)
        {
            while (top >= 0 && top + 1 + remain > k && st[top] < num[i])
            {
                --top;
            }
            --remain;
            if (top + 1 < k)
                st[++top] = num[i];
        }
    }
    // 合并
    void merge(vector<int> &nums1, int size1, vector<int> &nums2, int size2, vector<int> &ret)
    {
        int l1 = 0, l2 = 0, l3 = 0;
        int m = size1, n = size2;
        if (m == 0)
        {
            ret = nums2;
            return;
        }
        if (n == 0)
        {
            ret = nums1;
            return;
        }
        while (l1 < m && l2 < n)
        {
            if (cmp(nums1, nums2, l1, l2))
                ret[l3++] = nums1[l1++];
            else
                ret[l3++] = nums2[l2++];
        }
        while (l1 < m)
            ret[l3++] = nums1[l1++];
        while (l2 < n)
            ret[l3++] = nums2[l2++];
    }
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size(), n = nums2.size();
        int l = max(0, k - n), r = min(m, k);
        vector<int> seq1, seq2, seq(k), st1(k), st2(k);
        vector<int> ans(k, 0);
        for (int i = l; i <= r; ++i)
        {
            getSeq(nums1, i, st1);
            getSeq(nums2, k - i, st2);
            merge(st1, i, st2, k - i, seq);
            if (cmp(seq, ans, 0, 0))
            {
                ans = seq;
            }
        }
        return ans;
    }
    bool cmp(vector<int> &nums1, vector<int> &nums2, int l1, int l2)
    {
        int m = nums1.size(), n = nums2.size();
        int i = l1, j = l2;
        while (i < m && j < n)
        {
            if (nums1[i] != nums2[j])
                return nums1[i] > nums2[j];
            i++;
            j++;
        }
        return m - l1 > n - l2;
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
    vector<int> a = {8, 6, 9};
    vector<int> b = {1, 7, 5};
    solution.maxNumber(a, b, 3);
    return 0;
}