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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int p[maxn], q[maxn];
int a[maxn][maxn];
vector<pair<int, int>> tmp;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - a.second) < abs(b.first - b.second);
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    set<int> seta, setb;
    for (int i = 1; i <= n; i++)
    {
        read(p[i]);
        setb.insert(p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        read(q[i]);
        seta.insert(q[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            tmp.push_back({q[i], p[j]});
        }
    }

    sort(tmp.begin(), tmp.end(), cmp);

    int ansa = 0, ansb = 0;

    auto s = tmp.begin(), e = tmp.end();
    while (s != e)
    {
        if (setb.count((*e).second))
        {
            setb.erase((*e).second);
            if (setb.size() == 1)
            {
                ansb = *(setb.begin());
            }
            
        }
        e--;
        if (seta.count((*s).second))
        {
            seta.erase((*s).second);
            if (seta.size() == 1)
            {
                ansa = *(seta.begin());
            }
            
        }
        s++;
    }

    printf("%d\n", abs(ansa - ansb));

    return 0;
}