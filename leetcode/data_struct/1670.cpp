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
class FrontMiddleBackQueue
{
public:
    deque<int> q1, q2;
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        q1.push_front(val);
        check();
    }

    void pushMiddle(int val)
    {
        q1.push_back(val);
        check();
    }

    void pushBack(int val)
    {
        q2.push_back(val);
        check();
    }

    int popFront()
    {
        int ret;
        if (q1.size() == 0)
        {
            if (q2.size() == 0)
                return -1;
            else
            {
                ret = q2.front();
                q2.pop_front();
                check();
            }
        }
        else
        {
            ret = q1.front();
            q1.pop_front();
            check();
        }
        return ret;
    }

    int popMiddle()
    {

        int ret;
        if (q1.size() == q2.size())
        {
            if (q1.size() == 0)
                return -1;
            ret = q1.back();
            q1.pop_back();
        }
        else
        {
            if (q2.size() == 0)
                return -1;
            ret = q2.front();
            q2.pop_front();
        }
        check();
        return ret;
    }

    int popBack()
    {
        int ret;
        if (q2.size() == 0)
        {
            if (q1.size() == 0)
                return -1;
            else
            {
                ret = q1.back();
                q2.pop_back();
                check();
            }
        }
        else
        {
            ret = q2.back();
            q2.pop_back();
            check();
        }
        return ret;
    }
    void check()
    {
        if (q1.size() + 2 <= q2.size())
        {
            q1.push_back(q2.front());
            q2.pop_front();
        }
        if (q1.size() >= q2.size() + 1)
        {
            q2.push_front(q1.back());
            q1.pop_back();
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

int t, n, m, k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    FrontMiddleBackQueue solution;
    solution.popMiddle();
    return 0;
}