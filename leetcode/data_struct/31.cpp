// #pragma GCC optimize(2)
#include <bits/stdc++.h>
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

struct ListNode
{
    int key;
    int val;
    int cnt;
    ListNode *pre, *next;
    ListNode()
    {
        pre = next = nullptr;
    }
};

class LRUCache
{
public:
    int capacity;
    ListNode *head, *tail;
    unordered_map<int, ListNode *> mp;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key)
    {
        if (!mp.count(key))
            return -1;
        erase(mp[key]);
        insertTail(mp[key]);
        return mp[key]->val;
    }

    void erase(ListNode *p)
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    void insertTail(ListNode *p)
    {
        p->pre = tail->pre;
        p->next = tail;
        tail->pre->next = p;
        tail->pre = p;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            ListNode *p = mp[key];
            p->val = value;
            erase(p);
            insertTail(p);
            return;
        }
        if (mp.size() == capacity)
        {
            // 删除最老的，链表首部。
            ListNode *p = head->next;
            erase(p);
            mp.erase(p->key);
            delete p;
        }
        ListNode *p = new ListNode();
        mp[key] = p;
        p->key = key, p->val = value;
        insertTail(p);
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
    LRUCache solution(2);
    solution.put(1, 1);
    solution.put(2, 2);
    cout << solution.get(1) << endl;
    solution.put(3, 3);
    cout << solution.get(2) << endl;
    return 0;
}