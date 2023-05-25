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
    const static int maxn = 1e3 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int p[maxn * 2];
    void manacher(const char *t, int n)
    {
        static char s[maxn * 2];
        int l = 0;
        s[l++] = '$';
        s[l++] = '#';
        for (int i = 0; i < n; ++i)
        {
            s[l++] = t[i];
            s[l++] = '#';
        }
        s[l] = '\0';
        int mx = 0, j = 0;
        for (int i = 1; i < l; ++i)
        {
            p[i] = (mx > i ? min(p[j * 2 - i], mx - i) : 1);
            while (i - p[i] != -1 && i + p[i] != l && s[i - p[i]] == s[i + p[i]])
                p[i]++;
            if (i + p[i] > mx)
            {
                mx = i + p[i];
                j = i;
            }
        }
    }
    string longestPalindrome(string s)
    {
        int n = s.length();
        manacher(s.c_str(), n);
        int maxx = 0, index = -1;
        for (int i = 1; i < n * 2 + 2; ++i)
        {
            cout << p[i] - 1 << endl;
            if (p[i] - 1 > maxx)
            {
                maxx = p[i] - 1;
                index = i / 2 - 1;
            }
        }
        return s.substr(index - (maxx - 1) / 2, maxx);
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
    cout << solution.longestPalindrome("aaba") << endl;
    return 0;
}