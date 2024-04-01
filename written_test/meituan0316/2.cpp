#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;

int n, m, q, k, t;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    n = s.length();
    int cntUpper = 0;
    int cntLower = 0;
    for (int i = 0; i < n; ++i)
    {
        if(isupper(s[i])) {
            cntUpper++;
        }
    }
    cntLower = n - cntUpper;
    int ans = min(cntLower, cntUpper);
    // ans = min(ans, cntUpper - isupper(s[0]));
    int tmp = cntUpper;
    if(isupper(s[0])) {
        tmp--;
    }
    ans = min(ans, tmp);
    cout << ans << endl;
    return 0;
}