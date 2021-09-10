#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 2e3 + 10;
const int maxm = 1e5 + 10;
int read()
{
    int x = 0, flag = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    }
    if (flag)
        return -x;
    return x;
}
int t, n, m, k;

struct Point
{
    int x;
    int y;
} point[maxn];

struct Edge
{
    ll dis;
    int a;
    int b;
    bool operator<(const Edge &rhs) const
    {
        return dis > rhs.dis;
    }
};
vector<Edge> edge;

ll getDis(Point a, Point b)
{
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

bool vis[maxn];
set<int> st;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    t = read();
    while (t--)
    {
        n = read();
        memset(vis, false, sizeof(vis));
        edge.clear();
        for (int i = 1; i <= n; i++)
        {
            point[i] = {read(), read()};
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                edge.push_back({getDis(point[i], point[j]), i, j});
            }
        }

        sort(edge.begin(), edge.end());
        int sum = n;
        bool flag = false;
        for (int i = 0; i < edge.size(); i++)
        {
            if (vis[edge[i].a] || vis[edge[i].b])
                continue;
            ll maxx = edge[i].dis;
            st.clear();
            int j = i;
            while (j < edge.size() && edge[j].dis == maxx)
            {
                if (vis[edge[j].a] || vis[edge[j].b])
                {
                    j++;
                    continue;
                }
                else
                {
                    st.insert(edge[j].a);
                    st.insert(edge[j].b);
                    j++;
                }
            }
            i = j - 1;
            for(auto it: st)
            {
                vis[it] = true;
            }
            if(vis[1] && sum > 1)
            {
                flag = true;
                break;
            }
            sum -= st.size();
        }

        if(flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        }
    return 0;
}