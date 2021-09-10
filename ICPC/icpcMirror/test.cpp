#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define eb emplace_back
#define pb push_back
#define qwerty1 first
#define qwerty2 second
#define qwerty3 ->first
#define qwerty4 ->second
#define umap unordered_map
#define uset unordered_set
#define pii pair<ll, ll>
#define pq priority_queue
#define dbg(x) cerr << #x << ": " << x << '\n'

using namespace std;

const ll N = 1e5 + 10;
const ll M = 998244353;
const ld PI = acos(-1);

ll n, k;
ll a[N], d[N], mn[N] = {INT_MAX};

signed main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    ll i, s = 0, ans = 0;

    cin >> n >> k;

    for (i = 1; i <= n; i++)
        cin >> a[i];

    for (i = 1; i <= n; i++)
        cin >> d[i], mn[i] = min(mn[i - 1], d[i]);

    for (i = n; i >= 1; i--)
        a[i] += a[i + 1];

    if (k == 0)
    {
        for (i = 1; i <= n; i++)
            ans = max(ans, a[i] - d[i]);

        cout << ans;
    }
    else if (k == 1)
    {
        for (i = 2; i <= n; i++)
            ans = max(ans, max(0ll, a[1] - a[i] - mn[i - 1]) + max(0ll, a[i] - d[i]));

        for (i = 1; i < n; i++)
            ans = max(ans, a[1] - (a[i + 1] - a[i + 2]) - d[1] + max(0ll, a[i + 1] - a[i + 2] - d[i + 1]));

        cout << ans;
    }
    else
        cout << max({0ll, a[1] - mn[n - 1], a[n] - d[n]});

    return 0;
}