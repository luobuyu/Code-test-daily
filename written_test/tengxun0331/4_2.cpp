#include <bits/stdc++.h>

using namespace std;
const int maxn = 4e2 + 10;
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
        preSum[i] = preSum[i - 1] ^ a[i];
    }

    for (int kk = 1; kk <= k; ++kk)
    {
        for (int i = kk; i <= n; ++i)
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