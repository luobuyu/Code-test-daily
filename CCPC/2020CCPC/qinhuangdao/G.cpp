#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int C[30][30];
void solve(int n)
{
    C[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
        }
    }
}
int main()
{
    solve(29);
    int T, n, k;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case)
    {
        scanf("%d%d", &n, &k);
        if (n == 1 || k >= 30 || k == 1)
        {
            printf("Case #%d: %d\n", Case, n);
            continue;
        }
        int lim = pow(n, (double)1 / k);
        int begin = 1;
        begin = pow(lim, k);
        int ans = 0;
        for (int i = 1; i < lim; ++i)
        {
            ans += 1;
            for (int j = 1; j < k; ++j)
            {
                ans += C[k][j] * pow(i, j - 1);
            }
        }
        for (int i = begin; i <= n; i += lim)
            ++ans;
        printf("Case #%d: %d\n", Case, ans);
    }
    return 0;
}