#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e8 + 10;
int n, m, k;
int dp[maxn];
int s[200];
int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for(int x, j = 1; j <= k; j++)
        {
            cin >> x;
            tmp |= 1 << (x - 1);
        }
        dp[tmp] = 1;
        s[i] = tmp;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < (1 << m); j++)
        {
            if(dp[j] == 0) continue;
            int tmp = s[i] | j;
            if(dp[tmp] == 0) dp[tmp] = dp[s[i]] + dp[j];
            else 
            {
                dp[tmp] = min(dp[tmp], dp[s[i]] + dp[j]);
            }
        }
    }
    // for(int i = 0; i < (1 << m); i++) cout << i << ".   " << dp[i] << endl;
    if(dp[(1 << m) - 1] == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[(1 << m) - 1] << endl;
    }
    return 0;
}