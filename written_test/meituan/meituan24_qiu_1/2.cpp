#include <bits/stdc++.h>
using namespace std;
int n, m, q, k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == t[i])
        {
            cnt++;
        }
    }
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (s[i] == t[i] || s[j] == t[j])
                continue;
            if (s[i] == t[j] && s[j] == t[i])
            {
                flag2 = true;
            }
            if (s[i] == t[j] || s[j] == t[i])
                flag1 = true;
        }
    }
    if (flag2)
    {
        cout << cnt + 2 << endl;
    }
    else if (flag1)
    {
        cout << cnt + 1 << endl;
    }
    else
    {
        cout << cnt << endl;
    }
    return 0;
}