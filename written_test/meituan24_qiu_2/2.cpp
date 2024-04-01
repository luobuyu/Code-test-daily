#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
int n, m, q, k;
long long a[maxn];
long long preSum[maxn];
long long solve(int l, int r, int aim)
{
    long long sub = 0;
    long long add = 0;
    for (int i = l; i <= r; ++i)
    {
        if(a[i] < aim)
            add += aim - a[i];
        else
            sub += a[i] - aim;
    }
    return max(add, sub);
}
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
    if(sum % n == 0) {
        cout << solve(1, n, sum / n);
    } else {
        // 排除 a[1]
        sort(a + 1, a + 1 + n);
        sum -= a[1];
        long long ans1 = min(solve(2, n, ceil(1.0 * sum / (n - 1))), solve(2, n, floor(1.0 * sum / (n - 1))));
        sum = sum + a[1] - a[n];
        long long ans2 = min(solve(1, n - 1, ceil(1.0 * sum / (n - 1))), solve(1, n - 1, floor(1.0 * sum / (n - 1))));
        cout << min(ans1, ans2) << endl;
    }

    return 0;
}