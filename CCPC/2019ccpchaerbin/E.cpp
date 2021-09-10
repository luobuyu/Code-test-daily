#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = nextChar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = nextChar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = nextChar();
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
const int maxn = 1e6 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

vector<int> s[maxn], g[maxn];

bool vis[maxn];
int indeg[maxn];
ll cnt[maxn];
int op[maxn];
queue<int> q;
unordered_map<int, ll> ans;
void init(int n)
{
    while (!q.empty())
        q.pop();
    for (int i = 1; i <= n; i++)
    {
        g[i].clear(), s[i].clear();
        vis[i] = indeg[i] = cnt[i] = 0;
    }
    ans.clear();
}
void bfs()
{
    q.push(n);
    vis[n] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            indeg[v]++;
            if (!vis[v])
            {
                q.push(v), vis[v] = 1;
            }
        }
    }
}

void topu()
{

    q.push(n);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            indeg[v]--;
            cnt[v] += cnt[u];
            if (indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] != 0 && op[i] == 1)
        {
            for (auto j : s[i])
            {
                ans[j] += cnt[i];
            }
        }
    }

    ll sum = 0, maxx = 0;
    for (auto &i : ans)
    {
        sum += i.second;
        if (maxx < i.second)
        {
            maxx = i.second;
        }
    }
    if (maxx * 2 >= sum)
    {
        cout << (sum - maxx) * 2 << endl;
    }
    else
        cout << sum << endl;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n);
        init(n);
        int a, b;
        for (int i = 1; i <= n; i++)
        {
            read(op[i]);
            if (op[i] == 1)
            {
                read(k);
                for (int j = 1, x; j <= k; j++)
                {
                    read(x);
                    s[i].emplace_back(x);
                }
            }
            else
            {
                read(a, b);
                g[i].emplace_back(a);
                g[i].emplace_back(b);
            }
        }
        cnt[n] = 1;
        bfs();
        topu();
        solve();
    }
    return 0;
}