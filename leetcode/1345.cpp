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

int t, n, m, k;

class Solution
{
public:
    const static int maxn = 5e4 + 10;
    unordered_map<int, int> mp;
    vector<int> g[maxn];
    bool vis[maxn];
    queue<int> q;
    int dis[maxn];
    int n;
    int get(int x)
    {
        if (!mp.count(x))
            mp[x] = mp.size();
        return mp[x];
    }
    int minJumps(vector<int> &arr)
    {
        memset(dis, 0x3f, sizeof(dis));
        n = arr.size();
        // 先离散化一下
        int maxx = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = get(arr[i]);
            g[arr[i]].push_back(i);
        }
        q.push(0);
        vis[0] = true;
        dis[0] = 0;
        while (q.size())
        {
            auto out = q.front();
            q.pop();
            // out 是个下标
            if (out == n - 1)
                break;
            for (int i = out - 1; i <= out + 1; i += 2)
            {
                if (i < 0 || i >= n || vis[i])
                    continue;
                if (dis[i] > dis[out] + 1)
                {
                    dis[i] = dis[out] + 1;
                    q.push(i);
                    vis[i] = true;
                }
            }
            for (int i = 0; i < g[arr[out]].size(); i++)
            {
                int v = g[arr[out]][i];
                if (v == out || vis[v])
                    continue;
                if (dis[v] > dis[out] + 1)
                {
                    dis[v] = dis[out] + 1;
                    q.push(v);
                    vis[v] = true;
                }
            }
            g[arr[out]].clear();
        }
        return dis[n - 1];
    }
};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.emplace_back(x);
    }
    Solution s;
    cout << s.minJumps(a) << endl;
    return 0;
}