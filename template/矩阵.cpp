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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
ll qpow(ll a, ll b, ll mod)
{
    ll ans = 1, tmp = a;
    while (b)
    {
        if (b & 1)
            ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;
        b >>= 1;
    }
    return ans % mod;
}
// 使用的时候注意一下矩阵乘法自带mod，矩阵的len，type等
struct Matrix
{
    using type = ll;
    static const int len = maxn;
    type a[len][len];
    int m, n; // 矩阵的行列
    int dim;  // 矩阵的维度
    // 构造函数
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
    Matrix(int a[][len], int n, int m)
    {
        this->n = n, this->m = m;
        copy(a, n, m);
    }
    Matrix(int a[][len], int n)
    {
        this->n = this->m = n;
        copy(a, n, n);
    }

    void copy(int a[][len], int n, int m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                this->a[i][j] = a[i][j];
            }
        }
    }
    void copy(int a[][len])
    {
        copy(a, n, m);
    }
    // type = 0, 行， 1 列
    Matrix(int a[], int n, int m, int type)
    {
        this->n = n, this->m = m;
        copy(a, n, m, type);
    }
    Matrix(int a[], int n, int type)
    {
        this->n = this->m = n;
        copy(a, n, n, type);
    }

    void copy(int a[], int n, int m, int type)
    {
        clean();
        int tmp[2] = {n, m};
        for (int i = 1; i <= tmp[type]; i++)
        {
            if (type == 0)
                this->a[1][i] = a[i];
            else
                this->a[i][1] = a[i];
        }
    }
    void copy(int a[])
    {
        clean();
        if (n == 1)
        {
            for (int i = 1; i <= m; i++)
            {
                this->a[1][i] = a[i];
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                this->a[i][1] = a[i];
            }
        }
    }
    // 传入 ch 构造特殊矩阵，i 单位矩阵
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
    // 清空矩阵元素
    void clean()
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                a[i][j] = 0;
    }

    // 基本运算符重载
    type *operator[](const int x)
    {
        return a[x];
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

    // 矩阵乘法，带模除
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

    // 矩阵快速幂，创建单位矩阵，需要和矩阵乘法一起使用
    Matrix matrixqpow(ll k)
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

    // ********矩阵变换************//
    // 交换第 x 行和第 y 行
    void swap(int x, int y)
    {
        for (int i = 1; i <= m; i++)
        {
            swap(a[x][i], a[y][i]);
        }
    }
    // 将 x 行，所有元素乘以 k
    void mul(int x, type k)
    {
        for (int i = 1; i <= m; i++)
        {
            // 同时将负的变成正的
            a[x][i] = (1ll * a[x][i] * k % mod + mod) % mod;
        }
    }
    // 将 x 行元素乘 k 加到 y
    void muladd(int x, int y, ll k)
    {
        for (int i = 1; i <= m; i++)
        {
            a[y][i] = ((a[y][i] + 1ll * a[x][i] * k % mod) % mod + mod) % mod;
        }
    }
    // 矩阵求逆
    bool inv(Matrix &ret)
    {
        if (this->n != this->m)
        {
            return false;
        }
        Matrix x(n, 'i');
        ret = x;
        for (int i = 1; i <= n; i++)
        {
            // a[i][i] = 0
            if (!a[i][i])
            {
                // 下面几行，把非零元素交换过来
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j][i])
                    {
                        swap(i, j), ret.swap(i, j);
                        break;
                    }
                }
            }
            // 没有找到非零元素
            if (!a[i][i])
            {
                return false;
            }
            // 找到了，交换成功
            ll invx = qpow((this->a)[i][i], mod - 2, mod);
            ret.mul(i, invx), mul(i, invx);
            for (int j = i + 1; j <= n; j++)
            {
                ret.muladd(i, j, -a[j][i]), muladd(i, j, -a[j][i]);
            }
        }
        // 回带，A矩阵变成了上三角，对角线为 1，B矩阵变成了下三角
        for (int i = n - 1; i; i--)
            for (int j = i + 1; j <= n; j++)
                ret.muladd(j, i, -a[i][j]), muladd(j, i, -a[i][j]);
        return true;
    }
};

int t, n, m, k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    read(n);
    Matrix a(n), b(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            read(a[i][j]);
        }
    }
    if (a.inv(b))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%lld%c", a[i][j], " \n"[j == n]);
            }
            printf("\n");
        }
    }
    return 0;
}