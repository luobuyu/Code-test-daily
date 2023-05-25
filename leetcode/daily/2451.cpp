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
    string oddString(vector<string> &words)
    {
        int n = words[0].size();
        int m = words.size();
        for (int i = 0; i < n - 1; ++i)
        {
            int x = -100, y = -100, x_cnt = 0, y_cnt = 0, x_index, y_index;
            for (int j = 0; j < m; ++j)
            {
                int tmp = words[j][i + 1] - words[j][i];
                if (x == -100)
                {
                    x = tmp;
                    x_cnt = 1;
                    x_index = j;
                }
                else if (x == tmp)
                    x_cnt++;
                else if (x != -100 && y == -100)
                {
                    y = tmp;
                    y_cnt = 1;
                    y_index = j;
                }
                else if (y == tmp)
                    y_cnt++;
            }
            if (x_cnt == 1)
                return words[x_index];
            else if (y_cnt == 1)
                return words[y_index];
        }
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
    vector<string> a = {"adc", "wzy", "abc"};
    solution.oddString(a);
    return 0;
}