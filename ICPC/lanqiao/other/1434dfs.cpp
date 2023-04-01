#include <bits/stdc++.h>
#define ll long long
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

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int ans[maxn];
int cnt = 0;
void dfs(int step, int sum, int tot)
{
    if(step == tot + 1)
    {
        if(sum == n)
        {
            bool flag = true;
            for(int i = 1; i <= tot / 2; i++)
            {
                if(ans[i] != ans[tot - i + 1]) return;
            }
            for(int i = 1; i <= tot; i++)
            {
                printf("%d", ans[i]);
            }
            printf("\n");
            cnt++;
        }
    }
    else
    {
        if(sum >= n) return;
        int s = 0;
        if(step == 1) s = 1;
        for(int i = s; i <= 9; i++)
        {
            ans[step] = i;
            dfs(step + 1, sum + i, tot);
            ans[step] = 0;
        }
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    dfs(1, 0, 5);
    dfs(1, 0, 6);
    if(cnt == 0) printf("-1\n");
    return 0;
}