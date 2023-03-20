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
    string findLexSmallestString(string s, int a, int b)
    {
        int n = s.size();
        string ans = s;
        s = s + s;
        vector<bool> vis(s.size(), false);
        int gcd = __gcd(b, n);
        int minx, times, tmp;
        string t;
        // 枚举轮转后的起点，第一次遇到vis=true时，后面全是循环
        for (int start = 0; start < n; start += gcd)
        {
            t = s.substr(start, n);
            times = 0;
            minx = 9;
            for (int j = 0; j < 10; ++j)
            {
                tmp = (t[1] - '0' + j * a) % 10;
                if (tmp < minx)
                {
                    minx = tmp;
                    times = j;
                }
            }
            for (int j = 1; j < n; j += 2)
            {
                t[j] = '0' + (t[j] - '0' + times * a) % 10;
            }
            if (b & 1)
            {
                times = 0;
                minx = 9;
                for (int j = 0; j < 10; ++j)
                {
                    tmp = (t[0] - '0' + j * a) % 10;
                    if (tmp < minx)
                    {
                        minx = tmp;
                        times = j;
                    }
                }
                for (int j = 0; j < n; j += 2)
                {
                    t[j] = '0' + (t[j] - '0' + times * a) % 10;
                }
            }
            ans = min(ans, t);
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
    string s;
    cin >> s >> n >> t;
    solution.findLexSmallestString(s, n, t);
    return 0;
}