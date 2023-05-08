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
class LFUCache
{
public:
    struct Node
    {
        Node *next;
        Node *pre;
        int val;
        int key;
    };
    Node *head;
    Node *tail;
    int capacity;
    unordered_map<int, Node *> mp;
    LFUCache(int capacity)
    {
        head = new Node;
        tail = new Node;
        this->capacity = capacity;
        head->next = tail;
        tail->pre = head;
        head->pre = nullptr;
        tail->next = nullptr;
    }

    void erase(Node *p)
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    void insertLast(Node *p)
    {
        p->pre = tail->pre;
        p->next = tail;
        p->next->pre = p;
        p->pre->next = p;
    }

    void insertLast(int val)
    {
        Node *p = new Node;
        p->val = val;
        insertLast(p);
    }

    int get(int key)
    {
        if (mp.count(key))
        {
            erase(mp[key]);
            insertLast(mp[key]);
            return mp[key]->val;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            mp[key]->val = value;
            erase(mp[key]);
            insertLast(mp[key]);
        }
        else
        {
            if (mp.size() >= capacity)
            {
                Node *tmp = head->next;
                mp.erase(tmp->key);
                erase(tmp);
                delete tmp;
            }
            Node *p = new Node;
            mp[key] = p;
            p->val = value;
            p->key = key;
            insertLast(p);
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
    LFUCache solution(3);
    solution.put(2, 2);
    solution.put(1, 1);
    solution.get(2);
    solution.get(1);
    solution.get(2);
    solution.put(3, 3);
    solution.put(4, 4);
    solution.get(3);
    solution.get(2);
    solution.get(1);
    solution.get(4);
    return 0;
}