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
ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 10 + 10;
const int maxm = 1e5 + 10;
ll t, n, m, k;

// 使用的时候注意一下矩阵乘法自带mod，矩阵的len，type等
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

    type *operator[](const int x)
    {
        return a[x];
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

int lenof(ll n)
{
    int i;
    for (i = 0; n; i++)
        n /= 10;
    return i;
}
ll pow10(int x)
{
    ll ans = 1;
    for (int i = 1; i <= x; i++)
        ans *= 10;
    return ans;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, m);
    Matrix a(3, 1);
    mod = m;
    int len = lenof(n);
    a[1][1] = a[2][1] = a[3][1] = 1;
    for (int i = 0; i < len - 1; i++)
    {
        Matrix b(3, 3);
        b[1][1] = pow10(i + 1) % mod;
        b[1][2] = b[1][3] = b[2][2] = b[2][3] = b[3][3] = 1;
        m = pow10(i + 1) - pow10(i);
        a = (b.qpow(m - (i == 0 ? 1 : 0))) * a;
    }
    Matrix b(3, 3);
    b[1][1] = pow10(len) % mod;
    b[1][2] = b[1][3] = b[2][2] = b[2][3] = b[3][3] = 1;
    m = n - pow10(len - 1) + 1;
    a = (b.qpow(m - (len - 1 == 0 ? 1 : 0))) * a;
    printf("%lld\n", a[1][1]);
    return 0;
}