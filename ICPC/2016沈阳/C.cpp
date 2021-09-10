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
const ll mod = 2147493647;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e1 + 10;
const int maxm = 1e5 + 10;
ll t, n, m, k;

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
};
ll a, b;
int A_arr[maxn][maxn] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 1, 4, 6, 4, 1},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 4, 6, 4, 1},
    {0, 0, 0, 0, 1, 3, 3, 1},
    {0, 0, 0, 0, 0, 1, 2, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1}};
int base_arr[maxn] = {0, 0, 0, 16, 8, 4, 2, 1};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    Matrix base(base_arr, 7, 1);
    while (tcase--)
    {
        Matrix tmp(A_arr, 7);
        Matrix ans(7, 7);
        read(n, a, b);
        base[1][1] = b;
        base[2][1] = a;
        if (n == 1)
            ans.a[1][1] = a;
        else if (n == 2)
            ans.a[1][1] = b;
        else
        {
            ans = tmp.matrixqpow(n - 2);
            ans = ans * base;
        }
        printf("%lld\n", ans[1][1]);
    }
    return 0;
}