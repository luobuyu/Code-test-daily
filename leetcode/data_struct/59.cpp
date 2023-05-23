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
class MaxQueue
{
public:
    const static int maxn = 1e5 + 10;
    int q[maxn];
    int hh = 0, tt = -1;
    int q2[maxn];
    int h2 = 0, t2 = -1;
    // 单调减
    MaxQueue()
    {
    }

    int max_value()
    {
        if (empty())
            return -1;
        return q[hh];
    }

    bool empty() { return t2 < h2; }

    void push_back(int value)
    {
        while (tt >= hh && value > q[tt])
            --tt;
        q[++tt] = value;
        q2[++t2] = value;
    }

    int pop_front()
    {
        if (empty())
            return -1;
        if (q2[h2] == q[hh])
        {
            ++hh;
        }
        return q2[h2++];
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
    MaxQueue solution;
    solution.push_back(1);
    solution.push_back(2);
    solution.push_back(2);
    solution.max_value();
    solution.pop_front();
    solution.pop_front();
    solution.max_value();
    return 0;
}