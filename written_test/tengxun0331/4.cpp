#include <bits/stdc++.h>

using namespace std;
const int maxn = 4e2 + 10;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
int n, m, q, k;
long long a[maxn];
long long dp[maxn][maxn];
long long preSum[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        preSum[i] = (preSum[i - 1] ^ a[i]);
    }
    // if(k == 1) {
    //     cout << preSum[n] << endl;
    //     return 0;
    // }
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = -INF_LL;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int kk = max(1, k - n + i - 1); kk <= min(i, k); ++kk)
        {
            for (int p = kk - 1; p < i; ++p)
            {
                dp[i][kk] = max(dp[i][kk], dp[p][kk - 1] + (preSum[i] ^ preSum[p]));
            }
        }
    }
    cout << dp[n][k] << endl;

    return 0;
}