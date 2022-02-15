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
string s[maxn];
int a[maxn];
int b[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // 原来 i位置a[i]跑到了 a[a[i]]
        // 就是 i -> a[i]
        // 逆 a[i] -> i
        cin >> a[i];
        b[a[i]] = i;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    string ch;
    for (int i = 1; i <= n; i++)
    {
        cin >> ch;
        s[i] = ch;
    }
    // s[i]
    // b 是转换数组
    for (int i = 1; i <= n; i++)
    {
        a[b[b[b[i]]]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << s[a[i]] << endl;
    }
    return 0;
};

// 1 5 2 3 4
// 1 3 4 5 2
// 1 4 5 2 3     ----1
// 1 5 2 3 4     ----2
// 1 2 3 4 5     ----3

// 1 2 3 4 5
// 1 5 2 3 4
// 1 3 4 5 2     ----1
// 1 4 5 2 3     ----2
// 1 5 2 3 4     ----3
