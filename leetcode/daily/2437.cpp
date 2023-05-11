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
auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    int ans = 0;
    bool check(string &s)
    {
        int hour = (s[0] - '0') * 10 + s[1] - '0';
        int minute = (s[3] - '0') * 10 + s[4] - '0';
        if (hour >= 24 || minute >= 60)
            return false;
        return true;
    }
    void dfs(int step, string &s)
    {
        if (step == 5)
        {
            if (check(s))
            {
                cout << s << endl;
                ans++;
            }
            return;
        }
        if (s[step] == '?')
        {
            for (int i = 0; i <= 9; ++i)
            {
                s[step] = '0' + i;
                dfs(step + 1, s);
            }
            s[step] = '?';
        }
        else
            dfs(step + 1, s);
    }
    int countTime(string time)
    {
        dfs(0, time);
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
    solution.countTime("0?:0?");
    cout << solution.ans << endl;
    return 0;
}