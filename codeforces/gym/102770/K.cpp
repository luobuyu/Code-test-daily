#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0;
    char ch = getchar();
    bool f = 1;
    for (; ch > '9' || ch < '0'; ch = getchar())
        if (ch == '-')
            f = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? x : -x;
}
const int N = 102;
int n, a[N], b[N];
int main()
{
    for (int T = read(); T--;)
    {
        n = read();
        for (int i = 1; i <= n; ++i)
            a[i] = read();
        for (int i = 1; i <= n; ++i)
            b[i] = read();
        int ans = -1;
        for (int i = 1; i <= n; ++i)
            if (a[i] * 3 < b[i])
            {
                ans = i;
                break;
            }
        printf("%d\n", ans);
    }
    return 0;
}