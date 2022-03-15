#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 2e1;

int dp[MAXN];

void Initial()
{
    fill(dp, dp + MAXN, 0);
    dp[0] = 1;
    for (int i = 1; i < MAXN; i = 2 * i)
    {
        for (int j = i; j < MAXN; ++j)
        {
            dp[j] += dp[j - i];
            dp[j] %= 1000000000;
        }
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n;
    Initial();
    while (scanf("%d", &n) != EOF)
    {
        printf("%d == %d\n", n, dp[n]);
    }
    return 0;
}