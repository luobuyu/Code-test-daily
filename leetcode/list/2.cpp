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
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int add = 0;
        ListNode *p1 = l1, *p2 = l2, *pre = nullptr;
        while (p1 && p2)
        {
            p1->val = p1->val + p2->val + add;
            add = p1->val / 10;
            p1->val = p1->val % 10;
            pre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1)
        {
            p1->val = p1->val + add;
            add = p1->val / 10;
            p1->val = p1->val % 10;
            pre = p1;
            p1 = p1->next;
        }
        while (p2)
        {
            ListNode *p = new ListNode;
            p->val = p2->val + add;
            add = p->val / 10;
            p->val = p->val % 10;
            pre->next = p;
            pre = p;
            p2 = p2->next;
        }
        while (add)
        {
            ListNode *p = new ListNode;
            p->val = add;
            add = p->val / 10;
            p->val = p->val % 10;
            pre->next = p;
            pre = p;
        }
        return l1;
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

    return 0;
}