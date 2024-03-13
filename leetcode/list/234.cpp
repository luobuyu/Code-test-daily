// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
using namespace std;
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{
    static string buf_line;
    static int _i;
    static int _n;
    static char _ch;
    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        _ch = buf_line[_i++];
        while (_ch < '0' || _ch > '9')
        {
            if (_ch == '-')
                flag = -1;
            _ch = buf_line[_i++];
        }
        while (_ch >= '0' && _ch <= '9')
        {
            x = (x << 3) + (x << 1) + (_ch ^ 48), _ch = buf_line[_i++];
        }
        x *= flag;
        return true;
    }

    template <class T, class... _T>
    inline bool read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline bool getline()
    {
        if (!getline(cin, buf_line))
            return false;
        _i = 0, _n = buf_line.length();
        return true;
    }
    template <class T>
    inline void show(T *a, int n)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            cout << a[i];
        }
        cout << "]";
    }

    bool endofl()
    {
        if (_i >= _n)
            return true;
        if (_i == 0)
            return false;
        if (buf_line[_i - 1] == ']')
        {
            _i++;
            return true;
        }
        return false;
    }

    template <class T, std::size_t Num>
    inline void show(T a[][Num], int n, int m)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            show(a[i], m);
        }
        cout << "]";
    }

} // namespace FAST_IO
using namespace FAST_IO;

// int init = []
// {
//     /*********** fast_read ***************/
//     freopen("user.out", "w", stdout);
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     /*************************************/

//     while (true)
//     {
//         if (!getline())
//             break;

//         getline();
//     }
//     exit(0);
//     return 0;
// }();

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
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = head, *cur = head->next;
        head->next = nullptr;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode *findMiddlePre(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *findMiddle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *endh1 = findMiddlePre(head);
        ListNode *h2 = endh1->next;
        endh1->next = nullptr;
        h2 = reverseList(h2);
        ListNode *h1 = head;
        // h2.len >= h1.len;
        bool ret = true;
        while (h2)
        {
            if (h1->val != h2->val)
            {
                ret = false;
                break;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        reverseList(h2);
        return ret;
    }
};

int t, n, m, k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<int> a = {1, 0, 1};
    ListNode *head = createList(a);
    solution.isPalindrome(head);
    return 0;
}
