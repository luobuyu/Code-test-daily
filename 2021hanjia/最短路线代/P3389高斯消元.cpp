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
const int maxm = 1e5 + 10;
int t, n, m, k;
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
    using type = double;
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
                    ret.a[i][j] = (ret.a[i][j] + this->a[i][k] * a.a[k][j]);
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
    void swaprow(int x, int y)
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
            a[x][i] = (a[x][i] * k);
        }
    }
    // 将 x 行元素乘 k 加到 y
    void muladd(int x, int y, ll k)
    {
        for (int i = 1; i <= m; i++)
        {
            a[y][i] = ((a[y][i] + a[x][i] * k));
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
        for (int i = 1; i <= n; i++) // 枚举列，一列一列的消
        {
            // a[i][i] = 0
            if (!a[i][i])
            {
                // 下面几行，把非零元素交换过来
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j][i])
                    {
                        swaprow(i, j), ret.swaprow(i, j);
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

    bool guass(Matrix &ret)
    {
        for (int i = 1; i <= m - 1; i++)
        {
            // 选出列主元
            int maxx = i;
            for (int j = i + 1; j <= n; j++)
            {
                if (fabs(a[j][i]) > fabs(a[maxx][i]))
                {
                    maxx = j;
                }
            }
            // 交换
            swaprow(maxx, i);

            if (fabs(a[i][i]) < eqs)
                return false;            // 无解
            for (int j = 1; j <= n; j++) // 该列的非主元全变为0
            {
                if (j != i)
                {
                    double tmp = a[j][i] / a[i][i];
                    for (int k = i + 1; k <= m; k++)
                    {
                        a[j][k] -= tmp * a[i][k];
                    }
                }
            }
        }
        Matrix x(m - 1, 1);
        ret = x;
        for (int i = 1; i <= m - 1; i++)
        {
            ret[i][1] = a[i][m] / a[i][i];
        }
        return true;
    }
};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    Matrix a(n, n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }
    Matrix ans(n, 1);
    if (a.guass(ans))
    {
        for (int i = 1; i <= ans.n; i++)
        {
            printf("%.2f\n", ans[i][1]);
        }
    }
    else
        printf("No Solution\n");

    return 0;
}