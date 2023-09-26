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
class LFUCache
{
public:
    struct Node
    {
        Node *pre, *next;
        int key, val;
        int cnt;
        Node() : pre(nullptr), next(nullptr), cnt(0) {}
        Node(int _key, int _val) : key(_key), val(_val), cnt(0), pre(nullptr), next(nullptr)
        {
        }
    };
    struct List
    {
        Node *head, *tail;
        List()
        {
            head = new Node();
            tail = new Node();
            head->next = tail;
            tail->pre = head;
        }
        void erase(Node *p)
        {
            p->pre->next = p->next;
            p->next->pre = p->pre;
        }
        void headInsert(Node *p)
        {
            p->next = head->next;
            head->next->pre = p;
            p->pre = head;
            head->next = p;
        }
        bool empty()
        {
            return head->next == tail;
        }
        void eraseTail()
        {
            erase(tail->pre);
        }
    };

    int size;
    unordered_map<int, List *> freq; // 次数，头指针（链表）
    unordered_map<int, Node *> mp;   // key, Node*
    int last_id;
    LFUCache(int capacity)
    {
        size = capacity;
        last_id = 0;
    }
    // 将 p节点从原来的，移动到新的桶
    void changeList(Node *p)
    {
        int old_bucket = p->cnt;
        int new_bucket = p->cnt + 1;
        p->cnt++;
        freq[old_bucket]->erase(p);
        if (freq[old_bucket]->empty())
        {
            if (old_bucket == last_id)
                last_id++;
            freq.erase(old_bucket);
        }
        if (!freq.count(new_bucket))
        {
            List *l = new List;
            freq[new_bucket] = l;
        }
        freq[new_bucket]->headInsert(p);
    }

    int get(int key)
    {
        if (mp.count(key))
        {
            // changeBucket
            changeList(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            Node *p = mp[key];
            changeList(p);
            p->val = value;
        }
        else
        {
            Node *p = new Node(key, value);
            mp[key] = p;
            if (mp.size() > size)
            {
                Node *tmp = freq[last_id]->tail->pre;
                mp.erase(tmp->key);
                freq[last_id]->erase(tmp);
                if (freq[last_id]->empty())
                    freq.erase(last_id);
                if (!freq.count(p->cnt))
                {
                    List *l = new List();
                    freq[p->cnt] = l;
                }
                freq[p->cnt]->headInsert(p);
                last_id = p->cnt;
            }
            else
            {
                if (!freq.count(p->cnt))
                {
                    List *l = new List();
                    freq[p->cnt] = l;
                }
                last_id = 0;
                freq[p->cnt]->headInsert(p);
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
    LFUCache solution(2);
    solution.put(1, 1);
    solution.put(2, 2);
    cout << solution.get(1) << endl;
    return 0;
}