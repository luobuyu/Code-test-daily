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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
queue<int> q;
int cnt[maxn];
int ans = 0;
void bfs()
{
    q.push(0);
    cnt[0] = 0;
    while (!q.empty())
    {
        auto out = q.front();
        q.pop();
        int v = (out + 1) % n;
        if (!(v == out || cnt[v] != 0 || v == 0))
        {
            cnt[v] = cnt[out] + 1;
            ans = max(ans, cnt[v]);
            q.push(v);
        }

        v = (out + k) % n;
        if (!(v == out || cnt[v] != 0 || v == 0))
        {
            cnt[v] = cnt[out] + 1;
            q.push(v);
            ans = max(ans, cnt[v]);
        }
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    // read(n, k);
    // dp[0] = 0;
    // int ans = 0;
    // for(int i = 1; i < n; i++)
    // {
    //     dp[i] = -1;
    // }
    // for(int i = 1; i < n; i++)
    // {
    //     if(dp[(i - k + n) % n] != -1)
    //     {
    //         dp[i] = min(dp[(i - k + n) % n], dp[(i - 1 + n) % n]) + 1;
    //     }
    //     else
    //     {
    //         dp[i] = dp[(i - 1 + n) % n] + 1;
    //     }
    //     printf("dp[%d]=%d\n", i, dp[i]);
    //     ans = max(ans, dp[i]);
    // }
    // cout << ans << endl;
    read(n, k);
    bfs();
    // for(int i = 0; i < n; i++)
    // {
    //     printf("cnt[%d]=%d\n", i, cnt[i]);
    // }
    cout << ans << endl;

    return 0;
}