#include <bits/stdc++.h>
#define F(i, j, k) for (int i = (j); i <= (k); ++i)
#define D(i, j, k) for (int i = (j); i >= (k); --i)
#define rep(it, s) for (__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define Rep(a, s) for (auto a : s)
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template <class Type>
ll quick_pow(Type x, Type y, Type Mod)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % Mod;
        x = x * x % Mod, y >>= 1;
    }
    return res;
}
template <class Type>
ll inv(Type x, Type Mod) { return quick_pow(x, Mod - 2, Mod); }
namespace IO
{
    template <class T>
    inline void read(T &x)
    {
        x = 0;
        int f = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                f = -1;
            ch = getchar();
        }
        while (ch <= '9' && ch >= '0')
            x = x * 10 + ch - '0', ch = getchar();
        x *= f;
    }
}; // namespace IO
using namespace IO;
int _, n;
const int N = 2005;
char ch[N][N];
int a[N][N];
int beginR[N][10], endR[N][10];
int beginC[N][10], endC[N][10];
int minR[10], maxR[10];
int minC[10], maxC[10];
int ans[10];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d\n", &_);
    while (_--)
    {
        scanf("%d\n", &n);
        F(i, 1, n)
        scanf("%s\n", ch[i] + 1);
        F(i, 1, n)
        {
            F(j, 0, 9)
            {
                beginR[i][j] = beginC[i][j] = 2001;
                endR[i][j] = endC[i][j] = -1;
                minR[j] = minC[j] = 2001;
                maxR[j] = maxC[j] = -1;
            }
        }
        F(i, 1, n)
        F(j, 1, n)
        {
            a[i][j] = ch[i][j] - '0';
            beginR[i][a[i][j]] = min(beginR[i][a[i][j]], j);
            endR[i][a[i][j]] = max(endR[i][a[i][j]], j);
            beginC[j][a[i][j]] = min(beginC[j][a[i][j]], i);
            endC[j][a[i][j]] = max(endC[j][a[i][j]], i);
            minR[a[i][j]] = min(minR[a[i][j]], i);
            maxR[a[i][j]] = max(maxR[a[i][j]], i);
            minC[a[i][j]] = min(minC[a[i][j]], j);
            maxC[a[i][j]] = max(maxC[a[i][j]], j);
        }
        F(k, 0, 9)
        ans[k] = 0;
        F(k, 0, 9)
        {
            F(i, 1, n)
            {
                ans[k] = max(ans[k], (endR[i][k] - beginR[i][k]) * max(i - 1, n - i));
                ans[k] = max(ans[k], (endR[i][k] - 1) * max(max(i - minR[k], 0), max(maxR[k] - i, 0)));
                ans[k] = max(ans[k], (n - beginR[i][k]) * max(max(i - minR[k], 0), max(maxR[k] - i, 0)));
                //cout<<k<<' '<<i<<' '<<ans[k]<<endl;
            }
            F(i, 1, n)
            {
                ans[k] = max(ans[k], (endC[i][k] - beginC[i][k]) * max(i - 1, n - i));
                ans[k] = max(ans[k], (endC[i][k] - 1) * max(max(i - minC[k], 0), max(maxC[k] - i, 0)));
                ans[k] = max(ans[k], (n - beginC[i][k]) * max(max(i - minC[k], 0), max(maxC[k] - i, 0)));
                //cout<<k<<' '<<i<<' '<<ans[k]<<endl;
                //cout<<endC[i][k]<<' '<<beginC[i][k]<<' '<<minC[k]<<' '<<maxC[k]<<endl;
            }
        }
        F(k, 0, 9)
        cout << ans[k] << ' ';
        cout << '\n';
    }
    return 0;
}