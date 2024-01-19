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
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    unordered_map<int, int> mp;
    int size = 0;
    int getVal(int x)
    {
        if (!mp.count(x))
        {
            mp[x] = ++size;
            return mp[x];
        }
        else
            return mp[x];
    }
    int maximumSetSize(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        for (auto &x : nums1)
            x = getVal(x);
        for (auto &y : nums2)
            y = getVal(y);
        vector<int> cnt1(size + 1), cnt2(size + 1);
        int tot1 = 0, tot2 = 0;
        int totdu = 0, totchong = 0;
        for (auto &x : nums1)
        {
            cnt1[x]++;
        }
        for (auto &x : nums2)
        {
            cnt2[x]++;
        }
        for (int i = 1; i <= size; ++i)
        {
            if (cnt1[i] == 0 && cnt2[i] != 0 || cnt1[i] != 0 && cnt2[i] == 0)
                ++totdu;
            if (cnt1[i] != 0 && cnt2[i] != 0)
                ++totchong;
            if (cnt1[i] > 1)
                tot1 += cnt1[i] - 1;
        }
        for (int i = 1; i <= size; ++i)
        {
            if (cnt2[i] > 1)
                tot2 += cnt2[i] - 1;
        }
        if (tot1 >= n / 2 && tot2 >= n / 2)
        {
            return totdu + totchong;
        }
        if (tot1 < n / 2 && tot2 < n / 2)
        {
            if (tot1 + tot2 + totchong >= n)
                return totdu + totchong;
            else
                return totdu + totchong - (n - tot1 - tot2 - totchong);
        }
        // 一个大于，一个小于
        if (tot1 > tot2)
        {
            swap(tot1, tot2);
            swap(cnt1, cnt2);
        }
        // 只算tot1
        if (tot1 + totchong >= n / 2)
            return totdu + totchong;
        else
        {
            return totdu + totchong - (n - tot2 - tot1 - totchong);
        }
        return -1;
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
    vector<int> a1 = {1, 2, 3, 4, 5, 6}, a2 = {2, 2, 2, 3, 3, 3};
    solution.maximumSetSize(a1, a2);
    return 0;
}