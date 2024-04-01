#include <bits/stdc++.h>
using namespace std;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n, k;
    long long res = 0;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
    vector<long long> presum(n + 1, 0);
    for (int i = 0; i < n; i++)
        presum[i + 1] = presum[i] ^ nums[i];
    for (int i = 1; i <= n; ++i)
    {
        dp[0][i] = -INF_LL;
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int idx = i - 1; idx < j; idx++)
                dp[i][j] = max(dp[i - 1][idx] + (presum[j] ^ presum[idx]), dp[i][j]);
        }
    }
    cout << dp[k][n] << endl;
}
// 64 位输出请用 printf("%lld")