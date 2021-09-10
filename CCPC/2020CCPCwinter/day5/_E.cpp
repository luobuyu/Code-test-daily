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

const int N = 302;
int n;
int a[N], b[4];
int cnt[N][N];
bool relation[4][4];
int ans;
int main()
{
    freopen("in.txt", "r", stdin);
    int start = clock();
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 0; i < 4; ++i)
        b[i] = read();
    for (int i = 0; i < 3; ++i)
        for (int j = i + 1; j < 4; ++j)
            relation[i][j] = b[i] == b[j];
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cnt[i][j] = cnt[i + 1][j];
        }
        cnt[i][a[i]]++;
    }
    for (int i = 1; i <= n - 3; ++i)
    {
        for (int j = i + 1; j <= n - 2; ++j)
        {
            if (a[i] == a[j] != relation[0][1])
                continue;
            for (int k = j + 1; k <= n - 1; ++k)
            {
                if (a[i] == a[k] != relation[0][2] || a[j] == a[k] != relation[1][2])
                    continue;
                if (relation[0][3])
                {
                    ans += cnt[k + 1][a[i]];
                }
                else if (relation[1][3])
                    ans += cnt[k + 1][a[j]];
                else if (relation[2][3])
                    ans += cnt[k + 1][a[k]];
                else
                {
                    ans += n - k;
                    ans -= cnt[k + 1][a[i]];
                    if (!relation[0][1])
                        ans -= cnt[k + 1][a[j]];
                    if (!relation[0][2] && !relation[1][2])
                        ans -= cnt[k + 1][a[k]];
                }
            }
        }
    }
    printf("%d\n", ans);
    int end = clock();
    printf("%lf", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}