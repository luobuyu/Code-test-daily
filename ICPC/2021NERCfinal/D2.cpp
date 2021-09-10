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
const double eqs = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k, d;
double dp[maxn][10];
struct Node
{
    bool use;
    int x, y;
} pre[maxn][10];
int a[maxn];
vector<int> ans;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, d);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][a[i] % 10] = log(a[i]);
        pre[i][a[i] % 10] = {true, -1, a[i] % 10};
        for (int j = 0; j < 10; j++)
        {
            if (dp[i - 1][j])
            {
                // 不选
                if (dp[i][j] < dp[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][j];
                    pre[i][j] = {false, i - 1, j};
                }
                // 选
                if (dp[i - 1][j] + log(a[i]) > dp[i][j * a[i] % 10])
                {
                    dp[i][j * a[i] % 10] = dp[i - 1][j] + log(a[i]);
                    pre[i][j * a[i] % 10] = {true, i - 1, j};
                }
            }
        }
    }
    if (dp[n][d] == 0)
        printf("-1\n");
    else
    {
        int lastn = n, lastd = d;
        Node tmp;
        do
        {
            tmp = pre[lastn][lastd];
            if (tmp.use)
            {
                ans.push_back(a[lastn]);
            }
            // 注意不能直接lastn = pre[lastn][lastd].x,
            // 因为会导致lastn变了，导致lastd不正确
            lastn = tmp.x;
            lastd = tmp.y;
        } while (tmp.x != -1);
        printf("%d\n", ans.size());
        for (auto x : ans)
        {
            printf("%d ", x);
        }
        printf("\n");
    }

    return 0;
}