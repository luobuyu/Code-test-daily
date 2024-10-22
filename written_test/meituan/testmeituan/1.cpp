#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int n, m;

bool check(int num)
{
    int sum = 0;
    bool flag = false;
    while(num) {
        if((num % 10) & 1) {
            flag = true;
        }
        sum += num % 10;
        num /= 10;
    }
    return flag && (sum % 2 == 0);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    int cnt = 0;
    for(int i = 1, x; i <= n; ++i) {
        cin >> x;
        cnt += check(x);
    }
    cout << cnt << endl;
    return 0;
}