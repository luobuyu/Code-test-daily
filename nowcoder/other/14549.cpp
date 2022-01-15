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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
ll t, n, m, k;
struct Matrix
{
    ll a[2][2];
    Matrix operator*(Matrix x)
    {
        Matrix ret;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                ll sum = 0;
                for (int k = 0; k < 2; k++)
                {
                    sum = (sum + a[i][k] * x.a[k][j] % mod) % mod;
                }
                ret.a[i][j] = sum;
            }
        }
        return ret;
    }
};

Matrix qpow(Matrix a, ll b)
{
    Matrix ret;
    ret.a[0][0] = 1;
    ret.a[0][1] = 0;
    ret.a[1][0] = 0;
    ret.a[1][1] = 1;
    Matrix tmp = a;
    while (b)
    {
        if (b & 1)
        {
            ret = ret * tmp;
        }
        tmp = tmp * tmp;
        b >>= 1;
    }
    return ret;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    Matrix tmp;
    tmp.a[0][0] = 1;
    tmp.a[0][1] = 1;
    tmp.a[1][0] = 1;
    tmp.a[1][1] = 0;
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n);
        if (n <= 2)
        {
            cout << n << endl;
        }
        else
        {
            Matrix b = qpow(tmp, n - 2);
            cout << (b.a[0][0] * 2 % mod + b.a[1][0]) % mod << endl;
        }
    }
    return 0;
}