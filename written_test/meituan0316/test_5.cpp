#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;

int n, m, q, k, t;
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
            while (l1 <= r && nums[l0] - nums[l1] > upper)
                l1++;
            while (l2 <= r && nums[l0] - nums[l2] >= lower)
                l2++;

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
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    vector<int> a = {2147483647, -2147483648, -1, 0};
    Solution s;
    s.countRangeSum(a, -1, 0);
    return 0;
}