// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
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
#include <unordered_map>
struct Node
{
    int key, val, freq;
    Node *pre, *next;
    Node()
    {
        pre = next = nullptr;
        freq = 1;
    }
    Node(int _key, int _val) : key(_key), val(_val), freq(1) {}
};

struct List
{
    Node *head, *tail;
    int size;
    List()
    {
        head = new Node();
        tail = new Node;
        head->next = tail;
        tail->pre = head;
        size = 0;
    }
    void push_front(Node *p)
    {
        p->next = head->next;
        p->pre = head;
        head->next->pre = p;
        head->next = p;
        size++;
    }
    void erase(Node *p)
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
        size--;
    }
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * lfu design
     * @param operators int整型vector<vector<>> ops
     * @param k int整型 the k
     * @return int整型vector
     */
    unordered_map<int, List *> freq_list;
    unordered_map<int, Node *> mp;
    int min_freq;
    int capacity;
    void set(int key, int val)
    {
        if (mp.count(key))
        {
            Node *p = mp[key];
            p->val = val;
            changeBucket(p);
        }
        else
        {
            if (mp.size() == capacity)
            {
                while (!freq_list.count(min_freq))
                {
                    min_freq++;
                }
                List *l = freq_list[min_freq];
                l->erase(l->tail->pre);
                if (l->size == 0)
                {
                    freq_list.erase(min_freq);
                    while (!freq_list.count(min_freq))
                    {
                        min_freq++;
                    }
                }
            }
            Node *p = new Node(key, val);
            min_freq = 1;
            if (!freq_list.count(min_freq))
            {
                freq_list[min_freq] = new List();
            }
            freq_list[min_freq]->push_front(p);
            mp[key] = p;
        }
    }

    void changeBucket(Node *p)
    {
        List *lold = freq_list[p->freq];
        List *lnew;
        if (!freq_list.count(p->freq + 1))
        {
            lnew = freq_list[p->freq + 1] = new List();
        }
        else
        {
            lnew = freq_list[p->freq + 1];
        }
        lold->erase(p);
        if (min_freq == p->freq)
        {
            min_freq++;
        }
        if (lold->size == 0)
        {
            freq_list.erase(p->freq);
        }
        p->freq++;
        lnew->push_front(p);
    }
    int get(int key)
    {
        if (mp.count(key))
        {
            Node *p = mp[key];
            changeBucket(p);
            return p->val;
        }
        else
        {
            return -1;
        }
    }
    vector<int> LFU(vector<vector<int>> &operators, int k)
    {
        min_freq = 0;
        capacity = k;
        vector<int> ans;
        for (auto &op : operators)
        {
            if (op[0] == 1)
            {
                this->set(op[1], op[2]);
            }
            else
            {
                ans.emplace_back(get(op[1]));
            }
        }
        return ans;
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
    vector<vector<int>> a = {{1, 1, 1},
                             {1, 2, 2},
                             {1, 3, 2},
                             {1, 2, 4},
                             {1, 3, 5},
                             {2, 2},
                             {1, 4, 4},
                             {2, 1}};
    solution.LFU(a, 3);
    return 0;
}