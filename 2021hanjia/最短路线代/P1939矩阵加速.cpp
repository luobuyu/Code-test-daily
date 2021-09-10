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
const int maxn = 1e2 + 10;
const int maxm = 1e2 + 10;
ll t, n, m;
ll k;

struct Matrix
{
    using type = ll;
    static const int len = maxn;
    type a[len][len];
    int m, n; // 矩阵的行列
    int dim;  // 矩阵的维度
    Matrix(int n, int m)
    {
        this->m = m, this->n = n;
        clean();
    }
    Matrix(int n)
    {
        this->m = this->n = n;
        clean();
    }
    Matrix(int n, char ch)
    {
        this->m = this->n = n;
        if (ch == 'i' || ch == 'I')
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    a[i][j] = (i == j);
        }
    }

    void clean()
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                a[i][j] = 0;
    }

    Matrix operator=(const Matrix &a)
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                this->a[i][j] = a.a[i][j];
            }
        }
        return *this;
    }

    Matrix operator%(const ll &mod) const
    {
        Matrix ret(n, m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ret.a[i][j] = a[i][j] % mod;
            }
        }
        return ret;
    }

    Matrix operator%=(ll mod)
    {
        *this = *this % mod;
        return *this;
    }

    Matrix operator*(const Matrix &a) const
    {
        Matrix ret(n, a.m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= a.m; j++)
            {
                for (int k = 1; k <= m; k++)
                {
                    ret.a[i][j] = (ret.a[i][j] + this->a[i][k] * a.a[k][j] % mod) % mod;
                }
            }
        }
        return ret;
    }
    Matrix operator*=(const Matrix &a)
    {
        *this = (*this) * a;
        return *this;
    }

    Matrix qpow(ll k)
    {
        Matrix ans(n, 'i'), tmp = *this;
        while (k)
        {
            if (k & 1)
                ans = ans * tmp;
            tmp = tmp * tmp;
            k >>= 1;
        }
        return ans;
    }
};

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    Matrix a(3, 1);
    a.a[1][1] = a.a[2][1] = a.a[3][1] = 1;
    int tmp[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 1, 0}};
    Matrix base(3, 3);
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            base.a[i][j] = tmp[i][j];
        }
    }
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n);
        if (n <= 3)
        {
            printf("1\n");
            continue;
        }
        Matrix ans = base;
        ans = ans.qpow(n - 1);
        printf("%lld\n", (a * ans).a[3][1]);
    }

    return 0;
}