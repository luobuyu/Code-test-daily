#include<bits/stdc++.h>

using namespace std;
const int maxn = 500 + 10;

int n;
int a[maxn];
int dp[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = n + 1; i < 2 * n; i++)
        a[i] = a[i - n];

    int ans = 0;
    for (int k = 1; k <= n; k++)
    {
        int end = k + n - 1;
        int top = 0;
        dp[++top] = a[k];
        for (int i = k + 1; i <= end; i++)
        {
            if(a[i] > dp[top])
                dp[++top] = a[i];
            else
            {
                int pos = lower_bound(dp + 1, dp + top, a[i]) - dp;
                dp[pos] = a[i];
            }
        }
        ans = max(ans, top); // pos刚好为个数
    }
    printf("%d\n", n - ans);
    return 0;
}