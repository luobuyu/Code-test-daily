#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e3 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
int n, m, q, k;
int dp[maxn][maxn][2];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    long long ans = 0;
    n = s.length();
    for (int i = 0; i < n; ++i)
    {
        if(s[i] == '0')
            dp[i][i][1] = 1;
        else
            dp[i][i][0] = 1;
    }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (s[j] == '1')
                {
                    dp[i][j][0] = dp[i][j - 1][1] + 1;
                    dp[i][j][1] = dp[i][j - 1][0];
                }
                else
                {
                    dp[i][j][1] = dp[i][j - 1][0] + 1;
                    dp[i][j][0] = dp[i][j - 1][1];
                }
                ans += min(dp[i][j][0], dp[i][j][1]);
            }
        }
        
        cout << ans << endl;
    return 0;
}