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
class LRUCache
{
public:
    struct ListNode
    {
        ListNode *pre;
        ListNode *next;
        int key;
        int val;
    };
    int cap;
    int length;
    unordered_map<int, ListNode *> mp;
    ListNode *head;
    ListNode *tail;
    LRUCache(int capacity)
    {
        head = new ListNode;
        tail = new ListNode;
        head->next = tail;
        head->val = 0;
        tail->pre = head;
        tail->val = 0;
        head->pre = nullptr;
        tail->next = nullptr;
        cap = capacity;
        length = 0;
    }

    int get(int key)
    {
        if (mp.count(key))
        {
            ListNode *p = mp[key];
            erase(p);
            insert(p);
            return p->val;
        }
        else
            return -1;
    }

    void insert(ListNode *p)
    {
        if (p == nullptr)
            return;
        if (length == cap)
        {
            ListNode *t = head->next;
            erase(t);
            delete t;
        }
        mp[p->key] = p;
        length++;
        p->next = tail;
        p->pre = tail->pre;
        tail->pre->next = p;
        tail->pre = p;
    }

    void erase(ListNode *p)
    {
        if (p == tail || p == head)
            return;
        mp.erase(p->key);
        length--;
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            ListNode *p = mp[key];
            p->val = value;
            erase(p);
            insert(p);
        }
        else
        {
            ListNode *p = new ListNode;
            p->val = value;
            p->key = key;
            insert(p);
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
    LRUCache solution(2);
    solution.put(2, 1);
    solution.put(2, 2);
    solution.get(2);
    solution.put(1, 1);
    solution.put(4, 1);
    solution.get(2);
    return 0;
}