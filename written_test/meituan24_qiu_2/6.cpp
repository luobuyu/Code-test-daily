#include <bits/stdc++.h>

using namespace std;
const int maxn = 5e2 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
int n, m, q, k;
int a[maxn];
int dp[maxn][maxn];
int dfs(int index, int sum)
{
    if(index == n + 1)
        return sum == 0;
    if(sum >= 0 && dp[index][sum] != -1)
        return dp[index][sum];
    long long ans = 0;
    for (int i = 1; i <= sum; ++i)
    {
        if(a[index] == i) continue;
        ans = (ans + dfs(index + 1, sum - i)) % mod;
    }
    dp[index][sum] = ans;
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    memset(dp, -1, sizeof(dp));
    dfs(1, sum);
    cout << dp[1][sum] << endl;
    return 0;
}