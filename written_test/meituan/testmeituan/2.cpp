#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
int n, m, k;
int a[maxn];


bool check(int mid)
{
    int cnt = 0;
    int pre = a[1];
    for(int i = 1; i <= n; ++i) {
        if(pre <= a[i]) {
            cnt += mid;
        } else {
            cnt += a[i] + mid - pre;
        }
        if(cnt >= k)
            return true;
        pre = max(pre, a[i] + mid);
    }
    return cnt >= k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int l = 1, r = k;
    int ans = 0;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}