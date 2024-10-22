#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> nums, int k)
{
    int n = nums.size();
    int ans = 0;
    int cnt = 0; // 0 的数量;
    for (int l = 0, r = 0; r < n; ++r)
    {
        if (nums[r] == 0)
            cnt++;
        while (l <= r && cnt > k)
        {
            if (nums[l] == 0)
            {
                cnt--;
            }
            ++l;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0};
    cout << solve(a, 3) << endl;
    return 0;
}