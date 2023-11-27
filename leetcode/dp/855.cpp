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
int n;
int dist(int l, int r)
{
    if (l == -1 || r == n)
        return r - l - 1;
    return (r - l) >> 1;
}

class ExamRoom
{
public:
    struct Node
    {
        int l, r;
        bool operator<(const Node &p) const
        {
            int d1 = dist(l, r);
            int d2 = dist(p.l, p.r);
            if (d1 == d2)
                return l > p.l;
            else
                return d1 < d2;
        }
        Node(int _l, int _r) : l(_l), r(_r) {}
        Node() {}
    };
    struct cmp
    {
        bool operator()(const Node &p, const Node &q) const
        {
            if (p.l == q.l)
                return p.r < q.r;
            return p.l < q.l;
        }
    };
    priority_queue<Node> q;
    map<Node, int, cmp> mp;
    unordered_map<int, int> left;
    unordered_map<int, int> right;
    ExamRoom(int _n)
    {
        n = _n;
        q.push(Node(-1, n));
        mp[Node(-1, n)] = true;
    }

    int seat()
    {
        Node top = q.top();
        q.pop();
        while (q.size() && !mp.count(top))
        {
            top = q.top();
            q.pop();
        }
        mp.erase(top);
        if (top.l == -1)
        {
            left[0] = -1;
            right[-1] = 0;
            right[0] = top.r;
            left[top.r] = 0;
            q.push(Node(0, top.r));
            mp[Node(0, top.r)] = true;
            return 0;
        }
        if (top.r == n)
        {
            left[n - 1] = top.l;
            right[top.l] = n - 1;
            right[n - 1] = n;
            left[n] = n - 1;
            q.push(Node(top.l, n - 1));
            mp[Node(top.l, n - 1)] = true;
            return n - 1;
        }
        int index = (top.l + top.r) >> 1;
        if (top.l + 1 <= index - 1)
        {
            q.push(Node(top.l, index));
            mp[Node(top.l, index)] = true;
        }
        if (index + 1 <= top.r - 1)
        {
            q.push(Node(index, top.r));
            mp[Node(index, top.r)] = true;
        }
        left[index] = top.l;
        right[top.l] = index;
        right[index] = top.r;
        left[top.r] = index;
        return index;
    }

    void leave(int p)
    {
        int l = left[p];
        int r = right[p];
        right[l] = r;
        left[r] = l;
        mp.erase(Node(l, p));
        mp.erase(Node(p, r));
        mp[Node(l, r)] = true;
        q.push(Node(l, r));
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
    ExamRoom solution(9);
    cout << solution.seat() << endl;
    cout << solution.seat() << endl;
    cout << solution.seat() << endl;
    cout << solution.seat() << endl;
    solution.leave(4);
    cout << solution.seat() << endl;
    cout << solution.seat() << endl;
    cout << solution.seat() << endl;
    cout << solution.seat() << endl;
    cout << solution.seat() << endl;
    cout << solution.seat() << endl;
    solution.leave(3);
    cout << solution.seat() << endl;
    return 0;
}