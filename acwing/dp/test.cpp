#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn], b[maxn];
int F[maxn][maxn];
void solve(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                for (int k = 0; k < j; k++)
                    if (b[k] < a[i])
                        F[i][j] = max(F[i][j], F[i - 1][k] + 1);
            }
            else
                F[i][j] = F[i - 1][j];
        }
    }
    int mx = 0;
    for (int i = 1; i <= m; i++)
        mx = max(mx, F[n][i]);
    printf("%d\n", mx);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i);
    solve(n, n);
    return 0;
}