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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
unordered_map<int, int> mp;
int cnt = 0;
int getId(int id)
{
    if (!mp.count(id))
    {
        mp[id] = ++cnt;
    }
    return mp[id];
}
vector<int> tmp;
vector<pair<int, int>> edges;
vector<vector<pair<int, int>>> g;
void addEdge(int u, int v, int w)
{
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
}

vector<ll> dis;
vector<bool> vis;
priority_queue<pair<int, int>> q; // -dis, id
ll dijkstra(int start, int end)
{
    q.push({0, start});
    dis[start] = 0;
    while (q.size())
    {
        auto out = q.top();
        q.pop();
        int u = out.second;
        if (vis[u])
            continue;
        vis[u] = true;
        if (u == end)
            break;
        for (int i = 0; i < g[u].size(); ++i)
        {
            ll v = g[u][i].first, w = g[u][i].second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
    return dis[end];
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        tmp.emplace_back(u);
        tmp.emplace_back(v);
        edges.emplace_back(u, v);
    }
    tmp.emplace_back(1);
    tmp.emplace_back(n);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (auto &x : tmp)
        getId(x);
    g.resize(cnt + 1);
    dis.resize(cnt + 1, INF);
    vis.resize(cnt + 1);

    for (auto &edge : edges)
    {
        int u = getId(edge.first);
        int v = getId(edge.second);
        addEdge(u, v, 0);
    }
    for (int i = 1; i < tmp.size(); ++i)
    {
        int u = getId(tmp[i - 1]);
        int v = getId(tmp[i]);
        int w = tmp[i] - tmp[i - 1];
        addEdge(u, v, w);
    }
    cout << dijkstra(getId(1), getId(n)) << endl;
    return 0;
}