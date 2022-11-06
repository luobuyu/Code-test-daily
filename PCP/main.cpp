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
struct Ins
{
    int n, p;
    int *vx_num;
    int **vx;

} old, now;

int main()
{
    // #define COMP_DATA
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("old3038.txt", "r", stdin);
    cin >> old.n >> old.p;
    old.vx = new int *[old.n];
    old.vx_num = new int[old.n];
    for (int i = 0, t; i < old.n; ++i)
    {
        cin >> old.vx_num[i];
        old.vx[i] = new int[old.vx_num[i]];
        for (int j = 0, x; j < old.vx_num[i]; j++)
        {
            cin >> old.vx[i][j];
        }
        sort(old.vx[i], old.vx[i] + old.vx_num[i]);
    }
    freopen("now3038.txt", "r", stdin);
    cin >> now.n >> now.p;
    now.vx = new int *[now.n];
    now.vx_num = new int[now.n];
    for (int i = 0, t; i < now.n; ++i)
    {
        cin >> now.vx_num[i];
        now.vx[i] = new int[now.vx_num[i]];
        for (int j = 0, x; j < now.vx_num[i]; j++)
        {
            cin >> now.vx[i][j];
        }
    }
    int u, l;
    cin >> u >> l;
    l = 108039;
    for (int i = u; i > l; i--)
    {
        cin >> t;
        for (int j = 0, x; j < t; j++)
        {
            cin >> x;
            now.vx_num[x]--;
        }
    }

    for (int i = 0; i < now.n; i++)
    {
        sort(now.vx[i], now.vx[i] + now.vx_num[i]);
        if (old.vx_num[i] != now.vx_num[i])
        {
            cout << "比对失败" << endl;
            return 0;
        }
        for (int j = 0; j < old.vx_num[i]; j++)
        {
            if (old.vx[i][j] != now.vx[i][j])
            {
                cout << "比对失败" << endl;
                return 0;
            }
        }
    }
    cout << "比对通过， [" << u << ", " << l << ")" << endl;

    return 0;
}