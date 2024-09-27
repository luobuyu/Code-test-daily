#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 10;
int n, k;
int a[maxn][maxn];
int ans[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + s[j - 1] - '0';
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int len = 2; i + len - 1 <= n && j + len - 1 <= n; len += 2)
            {
                int p = i + len - 1;
                int q = j + len - 1;
                int cnt = a[p][q] - a[p][j - 1] - a[i - 1][q] + a[i - 1][j - 1];
                if (cnt * 2 == len * len)
                    ans[len]++;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")