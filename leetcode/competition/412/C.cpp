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
struct Node
{
    long long val;
    long long times;
    int index;
    Node() {}

    bool operator<(const Node &p) const
    {
        if (times == p.times)
        {
            if (val == p.val)
                return index > p.index;
            return val > p.val;
        }
        else
        {
            return times > p.times;
        }
    }
};

class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    long long qpow(long long a, long long b, long long &times)
    {
        long long ans = 1;
        long long tmp = a;
        while (b)
        {
            if (b & 1)
            {
                times += ans * tmp / mod;
                ans = ans * tmp % mod;
            }
            tmp = tmp * tmp % mod;
            b >>= 1;
        }
        return ans;
    };
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        if (multiplier == 1)
            return nums;
        vector<int> ans = nums;
        int n = nums.size();
        vector<Node> pairNum(n);
        priority_queue<Node> q;
        int index = -1;
        int maxx = -1;
        for (int i = 0; i < n; ++i)
        {
            pairNum[i].val = nums[i];
            pairNum[i].times = 0;
            pairNum[i].index = i;
            if (nums[i] > maxx)
            {
                index = i;
                maxx = nums[i];
            }
            q.push(pairNum[i]);
        }

        while (k)
        {
            auto out = q.top();
            if (out.index == index)
                break;
            q.pop();
            out.times = (out.times * multiplier + out.val * multiplier) / mod;
            out.val = out.val * multiplier % mod;
            q.push(out);
            k--;
        }

        long long times = k / n;
        long long left = k % n;

        while (left)
        {
            auto out = q.top();
            q.pop();
            out.times = (out.times * multiplier + out.val * multiplier) / mod;
            out.val = out.val * multiplier % mod;
            q.push(out);
            left--;
        }
        while (q.size())
        {
            auto out = q.top();
            q.pop();
            ans[out.index] = out.val * qpow(multiplier, times, out.times) % mod;
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
    vector<int> a = {889458628, 338743558, 875422936, 684907163, 233489834};
    solution.getFinalState(a, 246181588, 313380);
    return 0;
}