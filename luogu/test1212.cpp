#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline int read()
{
    char chr = getchar();
    int f = 1, ans = 0;
    while (!isdigit(chr))
    {
        if (chr == '-')
            f = -1;
        chr = getchar();
    }
    while (isdigit(chr))
    {
        ans = (ans << 3) + (ans << 1);
        ans += chr - '0';
        chr = getchar();
    }
    return ans * f;
}
void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
int n, m;
char a[4005][4005];
int l[4005][4005], r[4005][4005], up[4005][4005], ans1, ans2;
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            l[i][j] = r[i][j] = j, up[i][j] = 1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= m; j++)
            if (a[i][j] == a[i][j - 1] && a[i][j] == 'F')
                l[i][j] = l[i][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = m - 1; j >= 1; j--)
            if (a[i][j] == a[i][j + 1] && a[i][j] == 'F')
                r[i][j] = r[i][j + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i > 1)
                if (a[i][j] == a[i - 1][j] && a[i - 1][j] == 'F')
                {
                    l[i][j] = max(l[i][j], l[i - 1][j]);
                    r[i][j] = min(r[i][j], r[i - 1][j]);
                    up[i][j] = up[i - 1][j] + 1;
                }
            int a = r[i][j] - l[i][j] + 1;
            int b = min(a, up[i][j]);
            ans2 = max(a * up[i][j], ans2);
        }
    cout << ans2 * 3;
    return 0;
}
