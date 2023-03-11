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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

class Solution
{
public:
    unordered_map<int, int> mp;
    int getPower(int x)
    {
        if (mp.count(x))
            return mp[x];
        if (x & 1)
            return mp[x] = getPower(3 * x + 1);
        else
            return mp[x] = getPower(x / 2);
    }
    int getKth(int lo, int hi, int k)
    {
        vector<pair<int, int>> b;
        mp[1] = 0;
        for (int i = lo; i <= hi; ++i)
        {
            b.push_back({i, getPower(i)});
        }
        sort(b.begin(), b.end(), [](pair<int, int> x, pair<int, int> y)
             {
        if(x.second != y.second) return x.second < y.second;
        return x.first < y.first; });
        for (auto x : b)
        {
            cout << x.first << " " << x.second << endl;
        }
        return b[k - 1].first;
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
    int x, y, z;
    cin >> x >> y >> z;
    Solution s;
    cout << s.getKth(7, 11, 4) << endl;

    return 0;
}