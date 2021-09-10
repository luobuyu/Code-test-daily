#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
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
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k, cnt;
int ans;
map<string, int> mp;
struct Node
{
    map<string, int> mp;
    int s0, s1;
    bool flag;
    void init()
    {
        mp.clear();
        s1 = s0 = 0;
        flag = false;
    }
    int ch(string s)
    {
        if (mp.count(s))
            return mp[s];
        return mp[s] = ++cnt;
    }
} tree[maxn];
char ss[1010];

void dfs(int u)
{
    for (auto i : tree[u].mp)
    {
        int v = i.second;
        dfs(v);
        tree[u].s1 += tree[v].s1;
        tree[u].s0 += tree[v].s0;
    }
    if (u == 1)
        return;
    if (tree[u].s1 && !tree[u].s0)
    {
        ++ans;
        for (auto i : tree[u].mp)
        {
            --ans;
        }
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    while (tcase--)
    {
        for (; cnt; cnt--)
            tree[cnt].init();
        cnt = 1;
        ans = 0;

        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            int p = 1;
            string s = "";
            scanf("%s", ss + 1);
            for (int i = 1; ss[i]; ++i)
            {
                if (ss[i] == '/')
                {
                    p = tree[p].ch(s), s = "";
                }
                else
                {
                    s += ss[i];
                }
            }
            p = tree[p].ch(s);
            tree[p].flag = true;
            ++tree[p].s1;
        }

        for (int i = 1; i <= m; i++)
        {
            int p = 1;
            string s = "";
            scanf("%s", ss + 1);
            for (int i = 1; ss[i]; ++i)
            {
                if (ss[i] == '/')
                {
                    p = tree[p].ch(s), s = "";
                }
                else
                {
                    s += ss[i];
                }
            }
            p = tree[p].ch(s);
            tree[p].flag = false;
            ++tree[p].s0;
        }
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}