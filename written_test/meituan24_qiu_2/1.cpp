#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INT_LL = 0x3f3f3f3f3f3f3f3f;
int n, m, q, k;
long long a[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    long long ans = 0;
    for (int i = 1; i < n; ++i)
    {
        ans = max(ans, sum - a[i] - a[i + 1] + a[i] * a[i + 1]);
    }
    cout << ans << endl;
    return 0;
}