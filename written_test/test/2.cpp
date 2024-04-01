#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;

int n, m, q, k, t;
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    auto startTime = chrono::steady_clock::now();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    long long ans = 0;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j * j <= a[i]; ++j)
        {
            if (a[i] % j != 0)
                continue;
            int tmp1 = j;
            int tmp2 = a[i] / j;
            if (tmp1 == tmp2 && mp.count(tmp1))
                ans += mp[tmp1];
            else if (mp.count(tmp2))
                ans += mp[tmp2];
            else if (mp.count(tmp1))
                ans += mp[tmp1];
        }
        mp[a[i]]++;
    }
    cout << ans << endl;
    cout << chrono::duration<double, milli>(chrono::steady_clock::now() - startTime).count() << endl;
    return 0;
}