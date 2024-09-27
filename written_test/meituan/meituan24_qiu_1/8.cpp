#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
int n, m, q, k;
int a[maxn][maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    long long ans = INF_LL;
    long long tmp = sum;
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            tmp -= a[i][j];
        }
        ans = min(ans, abs(sum - tmp - tmp));
    }
    tmp = sum;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            tmp -= a[i][j];
        }
        ans = min(ans, abs(sum - tmp - tmp));
    }
    cout << ans << endl;
    return 0;
}