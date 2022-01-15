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
int t, n, m, k;

struct MyVector
{
    int a[maxn];
    int size;
    int &operator[](int i)
    {
        return a[i];
    }
    void erase(int i)
    {
        if (i != size - 1)
            swap(a[size - 1], a[i]);
        size--;
    }
    int sizes()
    {
        return this->size;
    }
};

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    MyVector aa;
    int b[5] = {1, 3, -1, 2, 1};
    for (int i = 0; i < 5; i++)
    {
        aa[i] = b[i];
    }
    aa.size = 5;
    for (int i = aa.size; i >= 0; --i)
    {
        if (aa[i] == -1)
        {
            aa.erase(i);
        }
    }
    cout << endl
         << endl;
    cout << aa.sizes() << endl;
    for (int i = 0; i < aa.size; ++i)
    {
        cout << aa[i] << " ";
    }
    cout << endl;

    return 0;
}