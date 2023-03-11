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
    void reorderList(ListNode *head)
    {
        // 找到中点，翻转一个，合并
        // head, h2;
        ListNode *fast = head, *h2 = head;
        if (fast->next == nullptr || fast->next->next == nullptr)
            return;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            h2 = h2->next;
        }
        // 得到两条链表，head和h2
        // 翻转h2;
        fast = h2;
        h2 = h2->next;
        fast->next = nullptr;
        ListNode *vir_h2 = new ListNode;
        vir_h2->val = -1;
        vir_h2->next = nullptr;
        ListNode *cur = h2, *nex;
        while (cur)
        {
            nex = cur->next;
            cur->next = vir_h2->next;
            vir_h2->next = cur;
            cur = nex;
        }
        ListNode *p1 = head, *p2 = vir_h2->next;
        ListNode *p1_nex, *p2_nex;
        while (p1 && p2)
        {
            p1_nex = p1->next;
            p2_nex = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p1_nex;
            p2 = p2_nex;
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
    cin >> n;
    ListNode *head = new ListNode, *tail = head;
    ListNode *p = nullptr;
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        p = new ListNode;
        p->val = x;
        p->next = nullptr;
        tail->next = p;
        tail = p;
    }
    solution.reorderList(head->next);
    return 0;
}