#include <bits/stdc++.h>
#define ll long long
#define lll __int128
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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
string s[maxn];
string st;
int vis[maxn];
int ans = 0;

int getCnt(string a, string b)
{
    string aa, bb;
    int cnt = 1e9;
    int len = min(a.length(), b.length());
    for (int l = 1; l <= len; l++)
    {
        aa = a.substr(a.length() - l);
        bb = b.substr(0, l);
        if (aa == bb)
            cnt = min(cnt, l);
    }
    return cnt;
}

void dfs(int step, string p)
{
    // cout << p << endl;
    int llll = p.length();
    ans = max(ans, llll);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] >= 2)
            continue;
        int l = min(s[step].length(), s[i].length());
        int cnt = 0;
        string tmp;
        cnt = getCnt(s[step], s[i]);
        if ((cnt >= 1 && cnt < l) || (cnt == 1 && step == n + 1))
        {
            vis[i]++;
            tmp = s[i].substr(cnt);
            dfs(i, p + tmp);
            vis[i]--;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    cin >> s[n + 1];
    dfs(n + 1, s[n + 1]);
    cout << ans << endl;
    return 0;
}