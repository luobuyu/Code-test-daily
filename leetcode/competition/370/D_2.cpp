// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
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
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
struct BIT
{
    vector<long long> tree;
    int n;
    BIT(int _n) : tree(_n + 1), n(_n) {}
    int lowbit(int x)
    {
        return x & -x;
    }
    void build(int cur, int l, int r)
    {
        for (int i = 1; i <= n; ++i)
        {
            tree[i] = 0;
            int j = i + lowbit(i);
            if (j <= n)
                tree[j] = max(tree[j], tree[i]);
        }
    }
    // 单点更新
    void update(int pos, long long k) // 修改pos 为 k
    {
        if (k < tree[pos])
            return;
        tree[pos] = k;
        pos += lowbit(pos);
        while (pos <= n)
        {
            tree[pos] = max(tree[pos], k);
            pos += lowbit(pos);
        }
    }

    long long query(int r)
    {
        long long maxx = 0;
        while (r >= 1)
        {
            maxx = max(maxx, tree[r]);
            r -= lowbit(r);
        }
        return maxx;
    }
};

auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    // 线段树维护 [-INF, nums[i] - i] 区间内最大值。
    long long maxBalancedSubsequenceSum(vector<int> &nums)
    {
        // 首先离散化。
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            nums[i] -= i;
        }
        auto b = nums;
        sort(b.begin(), b.end());
        // [-INF_LL, nums[i] - i] => [1, mp[nums[i] - i]]
        int size = 1;
        unordered_map<int, int> mp;
        mp[-INF_LL] = size++;
        for (auto &x : b)
        {
            if (!mp.count(x))
                mp[x] = size++;
        }
        BIT bit(size);
        bit.build(1, 1, size);
        long long ans = -INF_LL;
        for (int i = 0; i < n; ++i)
        {
            int x = mp[nums[i]];
            long long pre = bit.query(x);
            ans = max(ans, pre + nums[i] + i);
            bit.update(x, pre + nums[i] + i);
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
    vector<int> a = {3, 3, 5, 6};
    cout << solution.maxBalancedSubsequenceSum(a) << endl;
    return 0;
}