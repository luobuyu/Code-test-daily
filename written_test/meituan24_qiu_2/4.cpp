#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
int n, m, q, k;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> q;
    int x;
    while(q--)
    {
        cin >> m >> x;
        cout << (x / m + 1) << endl;
    }

    return 0;
}