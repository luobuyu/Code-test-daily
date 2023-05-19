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
class MedianFinder
{
public:
    priority_queue<int> leMedin;
    priority_queue<int, vector<int>, greater<int>> gtMedin;
    double curMedin;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (leMedin.empty() || num <= curMedin)
        {
            leMedin.push(num);
            if (leMedin.size() - gtMedin.size() > 1)
            {
                gtMedin.push(leMedin.top());
                leMedin.pop();
            }
        }
        else
        {
            gtMedin.push(num);
            if (gtMedin.size() - leMedin.size() >= 1)
            {
                leMedin.push(gtMedin.top());
                gtMedin.pop();
            }
        }
        if (leMedin.size() == gtMedin.size())
            curMedin = (leMedin.top() + gtMedin.top()) / 2.0;
        else
            curMedin = leMedin.top();
    }

    double findMedian()
    {
        return curMedin;
    }
};

class MedianFinder
{
public:
    multiset<int> set;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        set.insert(num);
    }

    double findMedian()
    {
        auto it = set.begin();
        int i = 0;
        while (i < (set.size() - 1) / 2)
        {
            ++i;
            ++it;
        }

        if (set.size() & 1)
        {
            return *it;
        }
        else
        {
            int a = *it;
            ++it;
            int b = *it;
            return (a + b) / 2.0;
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
    MedianFinder solution;

    return 0;
}