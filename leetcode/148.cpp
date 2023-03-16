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
    ListNode *merge_sort(ListNode *head, ListNode *tail)
    {
        // [)
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        // 找中点
        ListNode *fast = head, *slow = head;
        while (fast != tail)
        {
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
            slow = slow->next;
        }
        ListNode *left = merge_sort(head, slow);
        ListNode *right = merge_sort(slow, tail);
        return mix_merge(left, right);
    }

    ListNode *mix_merge(ListNode *left, ListNode *right)
    {
        // [left, mid), [mid, r)
        ListNode *head = new ListNode;
        ListNode *tail = head;
        ListNode *l = left, *r = right;
        while (l != nullptr && r != nullptr)
        {
            if (l->val < r->val)
            {
                tail->next = l;
                tail = l;
                l = l->next;
            }
            else
            {
                tail->next = r;
                tail = r;
                r = r->next;
            }
        }
        if (l != nullptr)
        {
            tail->next = l;
        }
        if (r != nullptr)
        {
            tail->next = r;
        }
        return head->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        return merge_sort(head, nullptr);
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