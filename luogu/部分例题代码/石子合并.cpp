#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;
int N, a[maxn], s[maxn], dp1[maxn][maxn], dp2[maxn][maxn];
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= N; i++) a[i + N] = a[i];
    for (int i = 1; i <= N * 2; i++) s[i] = s[i - 1] + a[i];
    //dp1[i][j] i..j 合并成一个石子的最小代价
    //dp1[i][j] = min(dp1[i][k]+dp1[k+1][j]+sum(a[i]..a[j]))
    for (int i = 1; i <= N * 2; i++) dp1[i][i] = 0;
    for (int l = 2; l <= N; l++)
    for (int i = 1, j = l; j <= N * 2; i++, j++)
    {
        dp1[i][j] = dp1[i][i] + dp1[i + 1][j] + s[j] - s[i - 1];
        for (int k = i + 1; k < j; k++)
            dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + s[j] - s[i - 1]);
    }

    //同理求最大的
    for (int i = 1; i <= N * 2; i++) dp2[i][i] = 0;
    for (int l = 2; l <= N; l++)
    for (int i = 1, j = l; j <= N * 2; i++, j++)
    {
        dp2[i][j] = dp2[i][i] + dp2[i + 1][j] + s[j] - s[i - 1];
        for (int k = i + 1; k < j; k++)
            dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + s[j] - s[i - 1]);
    }

    int ans1 = dp1[1][N], ans2 = dp2[1][N];
    for (int i = 2; i <= N; i++) {
        ans1 = min(ans1, dp1[i][i + N - 1]);
        ans2 = max(ans2, dp2[i][i + N - 1]);
    }
    printf("%d\n%d", ans1, ans2);
}