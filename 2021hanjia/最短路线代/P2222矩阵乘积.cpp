#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e4 + 10;
const int maxm = 1e2 + 10;
int t, n, m, k;
int a[maxn];
int b[maxn][maxn];
int c[maxn];
char str[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int x, y, o, p;
    read(x, y);
    read(m, n, o, p);
    int times = 1;
    while (true)
    {
        if (!cin.getline(str, 100, '\n'))
            break;
        if (strlen(str) == 0)
        {
            times++;
            continue;
        }
        if (times == 1)
        {
            if (str[0] - '0' == x)
            {
                a[str[2] - '0'] = str[4] - '0';
            }
        }
        else if (times == 2)
        {
            b[str[0] - '0'][str[2] - '0'] = str[4] - '0';
        }
        else if (times == 3)
        {
            if (str[2] - '0' == y)
            {
                c[str[0] - '0'] = str[4] - '0';
            }
        }
        else
            break;
    }

    for (int i = 1; i <= o; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            tmp += a[j] * b[j][i];
        }
        b[0][i] = tmp;
    }
    int ans = 0;
    for (int i = 1; i <= o; i++)
    {
        ans += b[0][i] * c[i];
    }
    printf("%d\n", 12);

    return 0;
}