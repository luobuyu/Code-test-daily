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
string e = "12345678x";
string s;
char op[] = "urdl";
unordered_map<string, int> g;
unordered_map<string, pair<string, char>> pre;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int getDis(int x, int t)
{
    return abs(x / 3 - t / 3) + abs(x % 3 - t % 3);
}

// 求曼哈顿距离
int getH(string s)
{
    int ret = 0;
    for (int i = 0; i < 9; i++)
    {
        if (s[i] != 'x')
        {
            // 注意 0-8
            ret += getDis(s[i] - '1', i);
        }
    }
    return ret;
}

void bfs()
{
    priority_queue<pair<int, string>> q;
    q.push({-getH(s), s});
    g[s] = 0;
    while (q.size())
    {
        auto out = q.top();
        q.pop();
        string u = out.second;
        if (u == e)
            break;
        int gu = g[u];
        int index = u.find('x');
        int x = index / 3, y = index % 3;
        string tmp = u;
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx < 0 || newx >= 3 || newy < 0 || newy >= 3)
                continue;
            swap(u[newx * 3 + newy], u[index]);
            if (!g.count(u) || g[u] > g[tmp] + 1)
            {
                g[u] = g[tmp] + 1;
                q.push({-g[u] - getH(u), u});
                pre[u] = {tmp, op[i]};
            }
            swap(u[newx * 3 + newy], u[index]);
        }
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    string tmps;
    char ch;
    for (int i = 1; i <= 9; i++)
    {
        cin >> ch;
        s += ch;
        if (ch != 'x')
        {
            tmps += ch;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            if (tmps[i] > tmps[j])
                cnt++;
        }
    }
    if (cnt & 1)
    {
        puts("unsolvable");
    }
    else
    {
        bfs();
        string ans;
        while (e != s)
        {
            ans += pre[e].second;
            e = pre[e].first;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}