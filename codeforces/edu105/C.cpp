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
vector<int> a1, a2, b1, b2;

int solve(vector<int> a, vector<int> b)
{
    int n = a.size(), m = b.size();
    set<int> s(a.begin(), a.end());
    int ans = 0, tmp = 0;
    // 先找到有多少一样的
    for (auto x : b)
    {
        if (s.count(x))
            tmp++;
    }
    ans = tmp;
    // 模拟
    for (int i = 0; i < m; i++)
    {
        if (s.count(b[i]))
        {
            tmp--;
            continue;
        }
        int up = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        int down = lower_bound(b.begin(), b.end(), b[i] - up + 1) - b.begin();
        ans = max(ans, tmp + i - down + 1);
    }

    return ans;
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
        read(n, m);
        a1.clear();
        a2.clear();
        b1.clear();
        b2.clear();
        // a1.push_back(0);
        // a2.push_back(0);
        // b1.push_back(0);
        // b2.push_back(0);
        for (int i = 1, x; i <= n; i++)
        {
            scanf("%d", &x);
            if (x < 0)
                a1.push_back(-x);
            else
                a2.push_back(x);
        }
        for (int i = 1, x; i <= m; i++)
        {
            scanf("%d", &x);
            if (x < 0)
                b1.push_back(-x);
            else
                b2.push_back(x);
        }
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());
        cout << solve(a1, b1) + solve(a2, b2) << endl;
    }

    return 0;
}