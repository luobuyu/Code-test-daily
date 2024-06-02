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
vector<int> g[maxn];
vector<int> rg[maxn];
vector<vector<int>> allCircle;
int indeg[maxn];
bool vis1[maxn];
bool vis2[maxn];
void dfs1(int u, vector<int> &cur)
{
    cur.emplace_back(u);
    vis1[u] = true;
    for (auto &v : g[u])
    {
        if (vis1[v])
            continue;
        dfs1(v, cur);
    }
}
void dfs2(int u, int &cnt)
{
    vis2[u] = true;
    cnt++;
    for (auto &v : rg[u])
    {
        if (vis2[v])
            continue;
        dfs2(v, cnt);
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // 内向基环树
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        g[i].emplace_back(x);
        indeg[x]++;
        rg[x].emplace_back(i);
    }
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        for (auto &v : g[u])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
    vector<int> circleNode;
    for (int i = 0; i < n; ++i)
    {
        if (indeg[i] != 0)
            circleNode.emplace_back(i);
    }
    sort(circleNode.begin(), circleNode.end());
    int index = -1;
    int maxVal = 0;
    int maxId = 0;

    for (auto &u : circleNode)
    {
        if (vis1[u])
            continue;
        vector<int> cur;
        dfs1(u, cur);
        allCircle.emplace_back(cur);
        int start = cur[0];
        // 反图dfs一遍，得到该连通块的数量。
        int cnt = 0;
        int L = cur.size();
        dfs2(start, cnt);
        int V = cnt - L;
        int curMaxId = 0;
        for (auto &x : cur)
        {
            curMaxId = max(curMaxId, x);
        }
        if (L - V == maxVal)
        {
            if (curMaxId > maxId)
            {
                maxId = curMaxId;
                index = allCircle.size() - 1;
            }
        }
        else if (L - V > maxVal)
        {
            maxVal = L - V;
            maxId = curMaxId;
            index = allCircle.size() - 1;
        }
    }
    for (auto &x : allCircle[index])
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}