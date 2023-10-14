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
class StockPrice
{
public:
    unordered_map<int, int> mp; // time, price
    int last_time;
    priority_queue<pair<int, int>> maxq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq;
    StockPrice()
    {
        last_time = -1;
    }

    void update(int timestamp, int price)
    {
        maxq.push({price, timestamp});
        minq.push({price, timestamp});
        mp[timestamp] = price;
        if (timestamp > last_time)
            last_time = timestamp;
    }

    int current()
    {
        return mp[last_time];
    }

    int maximum()
    {
        while (maxq.size() && mp[maxq.top().second] != maxq.top().first)
        {
            auto top = maxq.top();
            // cout << top.first << ", " << top.second << endl;
            maxq.pop();
            top.first = mp[top.second];
            maxq.push(top);
        }
        return maxq.top().first;
    }

    int minimum()
    {
        cout << minq.top().first << ", " << mp[minq.top().second] << endl;
        while (minq.size() && mp[minq.top().second] != minq.top().first)
        {
            auto top = minq.top();
            cout << top.first << ", " << top.second << endl;
            minq.pop();
            top.first = mp[top.second];
            minq.push(top);
        }
        return minq.top().first;
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
    StockPrice solution;
    solution.update(87, 9207);
    solution.update(93, 4215);
    solution.update(87, 2453);
    solution.maximum();
    solution.minimum();
    solution.minimum();
    solution.maximum();
    return 0;
}