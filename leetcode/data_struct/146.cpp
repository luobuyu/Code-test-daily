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
class LRUCache
{
public:
    struct Node
    {
        Node *pre;
        Node *next;
        int val;
        int key;
        Node(int _key, int _val)
        {
            val = _val;
            key = _key;
            pre = next = nullptr;
        }
        Node()
        {
            pre = next = nullptr;
        }
    };
    Node *head, *tail;
    unordered_map<int, Node *> mp;
    int size;
    LRUCache(int capacity)
    {
        size = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }

    void insert(Node *p)
    {
        // 头插
        p->next = head->next;
        p->pre = head;
        head->next = p;
        p->next->pre = p;
    }
    void erase(Node *p)
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    int get(int key)
    {
        if (mp.count(key))
        {
            Node *p = mp[key];
            erase(p);
            insert(p);
            return p->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            Node *p = mp[key];
            erase(p);
            insert(p);
            p->val = value;
        }
        else
        {
            Node *p = new Node(key, value);
            mp[key] = p;
            insert(p);
            if (mp.size() > size)
            {
                Node *q = tail->pre;
                mp.erase(q->key);
                erase(q);
                delete q;
            }
        }
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

    return 0;
}