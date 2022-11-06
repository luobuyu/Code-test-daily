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

struct Node
{
    int id;
    int *a;
    int n;
    Node &operator=(const Node &a)
    {
        cout << "====" << endl;
        n = a.n;
        for (int i = 0; i < n; i++)
        {
            this->a[i] = a.a[i];
        }
        return *this;
    }
    Node(const Node &x)
    {
        id = x.id;
        cout << id << endl;
        a = new int[x.n];
        for (int i = 0; i < x.n; i++)
        {
            a[i] = x.a[i];
        }
        n = x.n;
    }
    Node(int n, int id1) : n(n), id(id1)
    {
        a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = i;
        }
    }
    ~Node()
    {
        delete[] a;
    }
};

struct Nodeb
{
    Node a;
    Nodeb(Node c) : a(c) {}
};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int beta = 8;
    int gamma = 4;
    vector<int> a = {0, 1, 1, 3, 2, 4, 5, 7};
    nth_element(a.begin(), a.begin() + beta / 2 - gamma / 2, a.begin() + beta / 2, [](const int &lhs, const int &rhs)
                { return lhs > rhs; });
    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}