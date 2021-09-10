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
int a, b;
ll f[maxn][maxn]; // i,j   表示位数为 i,最高位为 j 的数的个数
int tmp[maxn];
ll getSum(ll x)
{
    int len = 0;
    while(x) 
    {
        tmp[++len] = x % 10;
        x /= 10;
    }
    ll sum = 0;
    // 位数比他少 1 的
    for(int i = 1; i <= len - 1; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            sum += f[i][j];
        }
    }
    // 位数相同的
    for(int i = 1; i < tmp[len]; i++)
    {
        sum += f[len][i];
    }

    for(int i = len - 1; i >= 1; i--)
    {
        for (int j = 0; j <= tmp[i] - 1; j++)
        {
            if(abs(j - tmp[i + 1]) >= 2)
                sum += f[i][j];
            
        }
        if(abs(tmp[i+1] - tmp[i]) < 2)
            break;
    }
    return sum;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif

    read(a, b);
    for(int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for(int i = 2; i <= 10; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            for(int k = 0; k <= 9; k++)
            {
                if(abs(j - k) >= 2)
                {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
    }
    printf("%lld\n", getSum(b + 1) - getSum(a));
    return 0;
}