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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int x, y, z;
map<int, int> mp;
vector<int> a;
vector<PII> b;
int newa[maxn];
int find(int k)
{
    int l = 0, r = a.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] == k)
            return mid;
        else if (a[mid] > k)
            r = mid - 1;
        else
            l = mid + 1;
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
    cin >> n >> x >> y >> z;
    a.push_back(-INF);
    a.push_back(INF);
    for (int i = 1, l, r; i <= n; i++)
    {
        cin >> l >> r;
        a.push_back(l);
        a.push_back(r + 1);
        b.push_back({l, r});
    }
    sort(a.begin(), a.end());
    // 去重
    a.erase(unique(a.begin(), a.end()), a.end());

    for (auto &item : b)
    {
        int li = find(item.first);
        int ri = find(item.second + 1);
        newa[0] += x;
        newa[li] += y - x;
        newa[ri] += z - y;
        newa[a.size() - 1] -= z;
    }

    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < a.size(); i++)
    {
        tmp += newa[i];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}