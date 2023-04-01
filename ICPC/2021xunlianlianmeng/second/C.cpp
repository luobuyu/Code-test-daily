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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
string s;
vector<int> q;

bool check(int n)
{
    s = to_string(n);
    for (int i = 0; i < s.length() / 2; i++)
    {
        int j = s.length() - i - 1;
        if (s[i] != s[j])
            return false;
    }
    return true;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int tcase;
    cin >> tcase;
    for (int i = 5; i <= 20000; i++)
    {
        if (check(i))
            q.push_back(i);
    }
    while (tcase--)
    {
        cin >> n;
        int l = ceil(1.0 * n * 1.2);
        cout << "Input cost :" << n << endl;
        int ans = q[lower_bound(q.begin(), q.end(), l) - q.begin()];
        cout << ans - n << " " << ans << endl
             << endl;
    }
    return 0;
}