#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int INF_LL = 0x3f3f3f3f3f3f3f3f;

int n, m, q, k, t;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    long long sum = 0;
    int x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        sum += x;
    }
    int y;
    cin >> x >> y;
    cout << sum - x - y << endl;
    return 0;
}