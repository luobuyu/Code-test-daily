// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
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
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;
    vector<int> c;
    int query(int pos)
    {
        int ans = 0;
        while (pos >= 1)
        {
            ans = max(ans, c[pos]);
            pos -= lowbit(pos);
        }
        return ans;
    }
    void add(int pos, int k, int n)
    {
        while (pos <= n)
        {
            c[pos] = max(c[pos], k);
            pos += lowbit(pos);
        }
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        vector<pair<int, int>> a;
        vector<int> dp(n, 0);
        int max_age = 0;
        for (int i = 0; i < n; ++i)
        {
            a.push_back({scores[i], ages[i]});
            max_age = max(ages[i], max_age);
        }
        c.resize(max_age + 1, 0);
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            dp[i] = query(a[i].second) + a[i].first;
            add(a[i].second, dp[i], max_age);
            ans = max(ans, dp[i]);
        }
        return ans;
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
    Solution solution;
    read(n);
    vector<int> scores;
    vector<int> ages;
    for (int i = 0; i < n; ++i)
    {
        read(k);
        scores.push_back(k);
    }
    for (int i = 0; i < n; ++i)
    {
        read(k);
        ages.push_back(k);
    }
    cout << solution.bestTeamScore(scores, ages) << endl;
    return 0;
}