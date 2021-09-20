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
string s, e;
unordered_map<string, bool> vis;
unordered_map<string, pair<string, char>> pre;
queue<string> q;
string move(string state, int x)
{
    string ret = state;
    if (x == 0)
    {
        // ret = state.substr(4, 4) + state.substr(0, 4);
        reverse(ret.begin(), ret.end());
    }
    else if (x == 1)
    {
        ret[0] = state[3];
        ret[1] = state[0];
        ret[2] = state[1];
        ret[3] = state[2];
        ret[4] = state[5];
        ret[5] = state[6];
        ret[6] = state[7];
        ret[7] = state[4];
    }
    else if (x == 2)
    {
        ret[1] = state[6];
        ret[2] = state[1];
        ret[5] = state[2];
        ret[6] = state[5];
    }
    return ret;
}
void bfs()
{
    if (s == e)
        return;
    q.push(s);
    vis[s] = true;
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        if (u == e)
            return;
        for (int i = 0; i < 3; i++)
        {
            string news = move(u, i);
            if (vis[news] == false)
            {
                pre[news] = {u, 'A' + i};
                q.push(news);
                vis[news] = true;
            }
        }
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    for (int i = 0, x; i < 8; i++)
    {
        read(x);
        e += x + '0';
    }
    for (int i = 1; i <= 8; i++)
        s += i + '0';
    bfs();
    int dis = 0;
    string ans;

    while (e != s)
    {
        dis++;
        auto tmp = pre[e];
        e = tmp.first;
        ans += tmp.second;
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", dis);
    if (dis > 0)
    {
        cout << ans << endl;
    }
    return 0;
}