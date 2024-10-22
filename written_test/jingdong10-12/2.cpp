#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 10;

int n, m, k, t;
int l, r;
int a[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./int.txt", "r", stdin);
#endif
    cin >> n;
    cin >> l >> r;
    int minx = l, maxx = r;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 0; i < n - 1; ++i) {
        if(a[i] <= minx || a[i] >= maxx) {
            flag = false;
            break;
        }
        if(a[i] < a[i + 1]) {  // 当前猜小了，
            minx = max(minx, a[i]);
        } else {
            // a[i] > a[i + 1]
            maxx = min(maxx, a[i]);
        }
    }
    if(flag) {
        int ans = 0;
        ans += (a[n - 1] - minx - 1) + (maxx - a[n - 1] - 1);
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}