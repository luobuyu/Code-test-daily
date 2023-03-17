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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *vir_head = new ListNode(0, head);
        int list_length = 0;
        ListNode *cur = vir_head->next;
        while (cur)
        {
            cur = cur->next;
            list_length++;
        }
        for (int length = 1; length < list_length; length <<= 1)
        {
            // 找到两个这样长度的链表
            ListNode *cur = vir_head->next;
            ListNode *tail = vir_head;
            while (cur)
            {
                ListNode *head1 = cur;
                for (int i = 1; i < length && cur != nullptr; ++i)
                {
                    cur = cur->next;
                }
                ListNode *head2 = nullptr;
                if (cur)
                {
                    head2 = cur->next;
                    cur->next = nullptr;
                    cur = head2;
                }
                for (int i = 1; i < length && cur != nullptr; ++i)
                {
                    cur = cur->next;
                }
                ListNode *nex = nullptr;
                if (cur)
                {
                    nex = cur->next;
                    cur->next = nullptr;
                }
                ListNode *m_head = merge(head1, head2);
                tail->next = m_head;
                while (tail->next)
                {
                    tail = tail->next;
                }
                cur = nex;
            }
        }
        return vir_head->next;
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *head = new ListNode(0, nullptr);
        ListNode *tail = head;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val < head2->val)
            {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
        }
        if (head1)
        {
            tail->next = head1;
        }
        if (head2)
        {
            tail->next = head2;
        }
        return head->next;
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
    ListNode *head = new ListNode;
    int x;
    ListNode *tail = head;
    while (cin >> x)
    {
        ListNode *p = new ListNode;
        p->val = x;
        p->next = nullptr;
        tail->next = p;
        tail = p;
    }
    ListNode *ans = solution.sortList(head->next);
    while (ans)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}