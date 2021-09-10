#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int dp[maxn][maxn][maxn], st[maxn], n, m, c;
char str[maxn][maxn]; int h[maxn], cnt[maxn];
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", str[i]);
    for (int j = 0; j < (1 << m); j++) {
        bool flag = false; //=true表示有互相攻击的
        int counter = 0; // 表示j 对应的一行有多少个炮兵
        for (int k = 0; k < m; k++)
        if (j >> k & 1) {
            flag |= (j >> k + 1 & 1) || (j >> k + 2 & 1);
            counter += 1;
        }
        if (!flag) st[++c] = j, cnt[c] = counter;
    }
    
    for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++)
        if (str[i][j] == 'H') h[i] |= 1 << j;
    
    for (int j = 1; j <= c; j++)
    for (int k = 1; k <= c; k++)
        if (!(st[j] & h[1]) && !(st[k] & h[2]) && !(st[j] & st[k])) dp[2][j][k] = cnt[j] + cnt[k];
    
    for (int i = 3; i <= n; i++)
    for (int l = 1; l <= c; l++)
    if (!(st[l] & h[i])) {
        for (int j = 1; j <= c; j++)
        for (int k = 1; k <= c; k++)
        if (!(st[l] & st[j]) && !(st[l] & st[k]))
            dp[i][k][l] = max(dp[i][k][l], dp[i - 1][j][k] + cnt[l]);
    }

    int ans = 0 ;
    for (int j = 1; j <= c; j++)
    for (int k = 1; k <= c; k++)
        ans = max(ans, dp[n][j][k]);
    printf("%d", ans);
}