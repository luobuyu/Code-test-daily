#include <bits/stdc++.h>

using namespace std;
static const int maxn = 1e5 + 10;

int n, m, k, t;

string ss[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./int.txt", "r", stdin);
#endif
    cin >> n;
    string s;
    int minx = 1e9;
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> ss[i];
        minx = min(minx, (int)ss[i].length());
        if(i == 0) {
            cout << ss[i] << endl;
            ans = ss[i].length();
        } else {
            if(ans != -1) {
                int len = 0;
                bool flag = true;
                for (int j = 0; j < minx; ++j)
                {
                    if (ss[i - 1][j] != ss[i][j])
                    {
                        len = j;
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    len = minx;
                if(len != 0) {
                    cout << ss[i].substr(0, len) << endl;
                } else {
                    cout << "-1" << endl;
                }
                ans = min(ans, len);
            } else {
                cout << "-1" << endl;
            }
        }
    }

    return 0;
}