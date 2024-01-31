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
vector<bool> notPrime;
vector<int> prime;
vector<int> from;
vector<int> cnt;
int init = [](int maxx)
{
    notPrime.resize(maxx + 1);
    notPrime[0] = notPrime[1] = true;
    from.resize(maxx + 1);
    cnt.resize(maxx + 1);
    for (int i = 2; i <= maxx; ++i)
    {
        if (!notPrime[i])
        {
            from[i] = i;
            prime.emplace_back(i);
            cnt[i] = 1;
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= maxx; ++j)
        {
            notPrime[i * prime[j]] = true;
            from[i * prime[j]] = prime[j];
            cnt[i * prime[j]] = cnt[i] + (from[i] != prime[j]);
            if (i % prime[j] == 0)
                break;
        }
    }
    return 0;
}(1e5);

class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    const static int mod = 1e9 + 7;
    long long qpow(long long a, long long b)
    {
        long long ret = 1, tmp = a;
        while (b)
        {
            if (b & 1)
                ret = ret * tmp % mod;
            tmp = tmp * tmp % mod;
            b >>= 1;
        }
        return ret;
    }
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        // 单调减栈
        vector<int> st(n);
        int top = -1;
        vector<int> left(n, -1), right(n, n);
        for (int i = 0; i < nums.size(); ++i)
        {
            while (top >= 0 && cnt[nums[st[top]]] < cnt[nums[i]])
            {
                right[st[top]] = i;
                --top;
            }
            if (top >= 0)
                left[i] = st[top];
            st[++top] = i;
        }
        // i, right[i] - i, i - left[i], 相乘
        long long ans = 1;
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](const int &x, const int &y)
             { return nums[x] > nums[y]; });
        for (auto &x : id)
        {
            if (k == 0)
                break;
            long long tot = (right[x] - x) * (x - left[x]);
            int times = min(tot, 1ll * k);
            ans = ans * qpow(nums[x], times) % mod;
            k -= times;
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
    vector<int> a = {8, 3, 9, 3, 8};
    cout << solution.maximumScore(a, 2) << endl;
    return 0;
}