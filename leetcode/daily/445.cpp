// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{
    static string buf_line;
    static int _i;
    static int _n;

    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        char ch = buf_line[_i++];
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = buf_line[_i++];
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = buf_line[_i++];
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

int init = []
{
    /*********** fast_read ***************/
    freopen("user.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*************************************/
    static const int maxn = 100 + 1;
    int a[maxn];
    int b[maxn];
    int l1, l2;
    while (true)
    {
        if (!getline())
            break;
        int x;

        while (read(x))
        {
            a[l1++] = x;
        }
        getline();
        while (read(x))
        {
            b[l2++] = x;
        }
        int i = l1 - 1, j = l2 - 1;
        int val = 0, add = 0;
        int aa, bb;
        cout << "[";
        while (i >= 0 || j >= 0 || add)
        {
            if (i != l1 - 1 && j != l2 - 1)
                cout << ",";
            if (i >= 0)
                aa = a[i];
            else
                aa = 0;
            if (j >= 0)
                bb = b[j];
            else
                bb = 0;
            val = aa + bb + add;
            cout << val % 10;
            add = val / 10;
            if (i >= 0)
                --i;
            if (j >= 0)
                --j;
        }
        cout << "]\n";
    }
    exit(0);
    return 0;
}();

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
        stack<int> s1, s2;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *virhead = new ListNode;
        int a = 0, b = 0, add = 0, val;
        while (s1.size() || s2.size() || add)
        {
            if (s1.size())
            {
                a = s1.top();
                s1.pop();
            }
            else
                a = 0;
            if (s2.size())
            {
                b = s2.top();
                s2.pop();
            }
            else
                b = 0;
            val = a + b + add;
            add = val / 10;
            val = val % 10;
            virhead->next = new ListNode(val, virhead->next);
        }
        return virhead->next;
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

    return 0;
}