#include <bits/stdc++.h>
#define ll long long
#define lll long long
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e2 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn], sum;
int gcd;

// int dp[maxn * 2000];
// bool check()
// {
//     dp[0] = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = sum / 2; j >= a[i]; j--)
//         {
//             dp[j] |= dp[j - a[i]];
//         }
//     }
//     return dp[sum / 2];
// }
bitset<maxn * 2000> dp;

bool check()
{
    dp.set(0);
    for (int i = 1; i <= n; i++)
    {
        dp |= (dp << a[i]);
    }
    return dp[sum / 2];
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    bool flag = false;
    int index = -1;
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        sum += a[i];
        if (a[i] & 1)
            flag = true, index = i;
        if (i == 1)
            gcd = a[i];
        else
        {
            gcd = __gcd(gcd, a[i]);
        }
    }

    if (sum & 1)
    {
        printf("0\n");
    }
    else
    {
        if (check())
        {
            if (flag)
            {
                printf("1\n%d\n", index);
            }
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    a[i] /= gcd;
                    if (a[i] & 1)
                    {
                        index = i;
                        break;
                    }
                }
                printf("1\n%d\n", index);
            }
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}