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
const int maxn = 3e2 + 10;
const int maxm = 1e5 + 10;
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
        else if (ch == 'u' || ch == 'U')
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    a[i][j] = INF_LL;
        }
    }

    void clean()
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                a[i][j] = 0;
    }
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

    Matrix operator*(const Matrix &a) const
    {
        Matrix ret(n, 'u');
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= a.m; j++)
            {
                for (int k = 1; k <= m; k++)
                {
                    // ret.a[i][j] = (ret.a[i][j] + this->a[i][k] * a.a[k][j] % mod) % mod;
                    ret.a[i][j] = min(ret.a[i][j], (this->a)[i][k] + a.a[k][j]);
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
        Matrix ans(n, 'u'), tmp = *this;
        for (int i = 1; i <= n; i++)
            ans[i][i] = 0;
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

int n, t, s, e;
map<int, int> id;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, t, s, e);
    int cnt = 0;
    Matrix g(t << 1, 'u');
    for (int i = 1, u, v, w; i <= t; i++)
    {
        read(w, u, v);
        if (!id.count(u))
            id[u] = ++cnt;
        if (!id.count(v))
            id[v] = ++cnt;
        int uu = id[u], vv = id[v];
        g[uu][vv] = g[vv][uu] = min((ll)w, g[uu][vv]);
    }
    g.n = g.m = cnt;
    g = g.qpow(n);
    printf("%lld\n", g[id[s]][id[e]]);
    return 0;
}