#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;

int n;
ll a[maxn];
ll b[maxn];

ll cal_sub(int n, ll q)
{
    // b[0, len - 1]
    sort(b, b + n);
    if(n == 1)
        return 1;
    if(b[1] % b[0] != 0)
        return 0;
    if(q != -1) {
        if(b[1] / b[0] != q) return false;
    }
    q = b[1] / b[0];
    for (int i = 2; i < n; ++i) {
        if(b[i] % b[i - 1] != 0 || b[i] / b[i - 1] != q) {
            return false;
        }
    }
    return true;
}
ll solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    ll ans = 0;
    // 假设公比是1，所有的都相等，求一下最大的。
    ans += cal_sub(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int len = 1; len <= 30 && i + len - 1 < n; ++len) {
            b[len - 1] = a[i + len - 1];
            ans += cal_sub(len, -1);
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    cin >> tcase;
    while(tcase--)
    {
        cout << solve() << endl;
    }
    return 0;
}