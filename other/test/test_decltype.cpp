// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
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
template <typename T, typename Func>
void my_sort(T st, T ed, Func less)
{
    for (T i = st; i != ed; i++)
    {
        T mi = i; // 最小值所在的/指针/迭代器
        for (T j = i; j != ed; j++)
        {
            if (less(*j, *mi))
            {
                mi = j;
            }
        }
        auto tmp = *i;
        *i = *mi;
        *mi = tmp;
    }
}
auto cmp = [](const int &x, const int &y) -> bool
{
    return x < y;
};

bool cmp2(const int &x, const int &y)
{
    return x < y;
};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[] = {12, 4, 10, 8, 3};
    my_sort(a, a + 5, [&](const int &x, const int &y)
            { return x > y; });
    for (int i = 0; i < 5; ++i)
    {
        cout << a[i] << endl;
    }
    return 0;
}