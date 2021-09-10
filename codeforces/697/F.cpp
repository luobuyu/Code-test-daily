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
    inline void read(T &x, _T &... y)
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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int row[maxn], lie[maxn];
char a[maxn][maxn], b[maxn][maxn];
bool ok()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == b[i][j] && (row[i] + lie[j]) % 2 == 0)
                continue;
            else if (a[i][j] != b[i][j] && (row[i] + lie[j]) % 2 == 1)
                continue;
            else
                return false;
    return true;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n);
        for (int i = 1; i <= n; i++)
            scanf("%s", a[i] + 1);
        for (int i = 1; i <= n; i++)
            scanf("%s", b[i] + 1);
        //第一行不操作
        row[1] = 0;
        for (int i = 1; i <= n; i++)
            if (a[1][i] == b[1][i])
                lie[i] = 0;
            else
                lie[i] = 1;
        for (int i = 2; i <= n; i++)
            if (a[i][1] == b[i][1])
                row[i] = lie[1];
            else
                row[i] = lie[1] ^ 1;
        if (ok())
        {
            printf("YES\n");
            continue;
        }
        row[1] = 1;
        for (int i = 1; i <= n; i++)
            if (a[1][i] == b[1][i])
                lie[i] = 1;
            else
                lie[i] = 0;
        for (int i = 2; i <= n; i++)
            if (a[i][1] == b[i][1])
                row[i] = lie[1];
            else
                row[i] = lie[1] ^ 1;
        if (ok())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
