//minamoto
#include <bits/stdc++.h>
using namespace std;
#define getc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
int read()
{
    int res, f = 1;
    char ch;
    while ((ch = getc()) > '9' || ch < '0')
        (ch == '-') && (f = -1);
    for (res = ch - '0'; (ch = getc()) >= '0' && ch <= '9'; res = res * 10 + ch - '0')
        ;
    return res * f;
}
char sr[1 << 21], z[20];
int C = -1, Z = 0;
inline void Ot() { fwrite(sr, 1, C + 1, stdout), C = -1; }
void write(int x)
{
    if (C > 1 << 20)
        Ot();
    if (x < 0)
        sr[++C] = '-', x = -x;
    while (z[++Z] = x % 10 + 48, x /= 10)
        ;
    while (sr[++C] = z[Z], --Z)
        ;
    sr[++C] = ' ';
}
const int N = 405, mod = 1e9 + 7;
int n;
struct Matrix
{
    int a[N][N];
    inline void clr() { memset(a, 0, sizeof(a)); }
    int *operator[](int x) { return a[x]; }
    void SWAP(int x, int y)
    {
        for (int i = 1; i <= n; ++i)
            swap(a[x][i], a[y][i]);
    }
    //交换某两行
    void MUL(int x, int k)
    {
        for (int i = 1; i <= n; ++i)
            a[x][i] = (1ll * a[x][i] * k % mod + mod) % mod;
    }
    //将某一行的所有元素乘上k
    void MD(int x, int y, int k)
    {
        for (int i = 1; i <= n; ++i)
            a[x][i] = ((a[x][i] + (1ll * a[y][i] * k % mod)) % mod + mod) % mod;
    }
    //将某一行的所有元素乘上k加到另一行去
    void print()
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                write(a[i][j]);
            sr[++C] = '\n';
        }
    }
} A, B;
int ksm(int a, int b = mod - 2)
{
    int res = 1;
    for (; b; b >>= 1, a = 1ll * a * a % mod)
        if (b & 1)
            res = 1ll * res * a % mod;
    return res;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    n = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            A[i][j] = read();
    for (int i = 1; i <= n; ++i)
        B[i][i] = 1;
    for (int i = 1; i <= n; ++i)
    {
        //消成上三角矩阵
        if (!A[i][i])
        {
            for (int j = i + 1; j <= n; ++j)
                if (A[j][i])
                {
                    A.SWAP(i, j), B.SWAP(i, j);
                    break;
                }
        }
        if (!A[i][i])
            return puts("No Solution"), 0;
        //如果消着消着某一列没有数了，说明无解
        int x = ksm(A[i][i]);
        B.MUL(i, x), A.MUL(i, x);
        for (int j = i + 1; j <= n; ++j)
            B.MD(j, i, -A[j][i]), A.MD(j, i, -A[j][i]);
    }
    //消成对角矩阵
    for (int i = n - 1; i; --i)
        for (int j = i + 1; j <= n; ++j)
            B.MD(i, j, -A[i][j]), A.MD(i, j, -A[i][j]);
    B.print();
    return Ot(), 0;
}