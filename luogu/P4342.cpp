#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int dp[2][maxn][maxn];
char op[maxn];
int a[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    read(n);
    scanf("\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%c %d ", &op[i], &a[i]);
        op[i + n] = op[i];
        a[i + n] = a[i];
    }
    memset(dp[0], 0x3f, sizeof(dp[0]));
    memset(dp[1], 0xc0, sizeof(dp[1]));
    for (int i = 1; i <= (n << 1) - 1; i++)
    {
        dp[0][i][i] = dp[1][i][i] = a[i];
    }

    for (int len = 2; len <= (n << 1) - 1 ; len++)
    {
        for (int i = 1; i + len - 1 <= 2 * n - 1; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                if (op[k + 1] == 't')
                {
                    dp[0][i][j] = min(dp[0][i][k] + dp[0][k + 1][j], dp[0][i][j]);
                    dp[1][i][j] = max(dp[1][i][k] + dp[1][k + 1][j], dp[1][i][j]);
                }
                else
                {
                    dp[0][i][j] = min(dp[0][i][j], min(dp[0][i][k] * dp[0][k + 1][j], min(dp[1][i][k] * dp[0][k + 1][j], min(dp[0][i][k] * dp[1][k + 1][j], dp[1][i][k] * dp[1][k + 1][j]))));
                    dp[1][i][j] = max(dp[1][i][j], max(dp[0][i][k] * dp[0][k + 1][j], max(dp[1][i][k] * dp[0][k + 1][j], max(dp[0][i][k] * dp[1][k + 1][j], dp[1][i][k] * dp[1][k + 1][j]))));
                }
            }
        }
    }

    int tmp = -INF;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (dp[1][i][i + n - 1] > tmp)
        {
            tmp = dp[1][i][i + n - 1];
            ans.clear();
            ans.push_back(i);
        }
        else if (dp[1][i][i + n - 1] == tmp)
        {
            ans.push_back(i);
        }
    }
    printf("%d\n", tmp);
    for (auto x : ans)
    {
        printf("%d ", x);
    }
    printf("\n");

        return 0;
}

