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

struct Node
{
    int val;
    int key;
    int cnt;
    Node *pre = nullptr;
    Node *next = nullptr;
    Node()
    {
        val = key = -1;
        cnt = 1;
    }
    Node(int key, int val)
    {
        this->val = val;
        this->key = key;
        cnt = 1;
    }
};
struct List
{
    Node *head, *tail;
    int size;
    List()
    {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->pre = head;
        size = 0;
    }
    ~List()
    {
        Node *p = head, *q;
        while (p)
        {
            q = p->next;
            delete p;
            p = q;
        }
    }
    void eraseNode(Node *p)
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
        size--;
    }
    void insertLast(Node *p)
    {
        p->next = tail;
        p->pre = tail->pre;
        p->pre->next = p;
        tail->pre = p;
        size++;
    }
    void insertLast(int key, int val)
    {
        Node *p = new Node(key, val);
        insertLast(p);
    }
    void eraseFirst()
    {
        Node *p = head->next;
        head->next = p->next;
        p->next->pre = head;
        size--;
        delete p;
    }
    Node *back()
    {
        return tail->pre;
    }
    Node *front()
    {
        return head->next;
    }
};
class LFUCache
{
public:
    unordered_map<int, Node *> key_map;
    unordered_map<int, List *> freq_map; // cnt
    int capacity;
    int min_freq;
    int cnt;
    LFUCache(int capacity) : capacity(capacity), cnt(0)
    {
    }

    int get(int key)
    {
        if (key_map.count(key))
        {
            Node *p = key_map[key];
            int old_cnt = p->cnt;
            p->cnt++;
            change_backet(p, old_cnt, p->cnt);
            return p->val;
        }
        else
            return -1;
    }

    void change_backet(Node *p, int b1, int b2)
    {
        // b1 原来的桶，b2 新的桶
        freq_map[b1]->eraseNode(p);
        if (freq_map[b1]->size == 0)
        {
            delete freq_map[b1];
            freq_map.erase(b1);
            if (b1 == min_freq)
                min_freq += 1;
        }

        if (freq_map.count(b2))
            freq_map[b2]->insertLast(p);
        else
        {
            List *l = new List;
            l->insertLast(p);
            freq_map[b2] = l;
        }
    }

    void eraseMinFreq()
    {
        key_map.erase(freq_map[min_freq]->front()->key);
        freq_map[min_freq]->eraseFirst();
        if (freq_map[min_freq]->size == 0)
        {
            delete freq_map[min_freq];
            freq_map.erase(min_freq);
        }
    }

    void put(int key, int value)
    {
        if (key_map.count(key))
        {
            Node *p = key_map[key];
            int old_cnt = p->cnt;
            p->val = value;
            p->cnt++;
            change_backet(p, old_cnt, p->cnt);
        }
        else
        {
            if (cnt == capacity)
            {
                // 删除一个频率最低最老的
                eraseMinFreq();
                cnt--;
            }
            if (freq_map.count(1))
                freq_map[1]->insertLast(key, value);
            else
            {
                List *l = new List;
                l->insertLast(key, value);
                freq_map[1] = l;
            }
            min_freq = 1;
            cnt++;
            key_map[key] = freq_map[1]->back();
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
    LFUCache solution(2);
    solution.put(1, 1);
    solution.put(2, 2);
    solution.get(1);
    solution.put(3, 3);
    solution.get(2);
    solution.get(3);
    solution.put(4, 4);
    solution.get(1);
    solution.get(3);
    cout << solution.get(4) << endl;

    return 0;
}