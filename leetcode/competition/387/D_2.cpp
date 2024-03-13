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
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> arr1, arr2;
        vector<int> mp1, mp2;
        arr1.emplace_back(nums[0]);
        mp1.emplace_back(nums[0]);
        arr2.emplace_back(nums[1]);
        mp2.emplace_back(nums[1]);
        int n = nums.size();
        for (int i = 2; i < n; ++i)
        {
            // int cnt1, cnt2;
            auto it1 = upper_bound(mp1.begin(), mp1.end(), nums[i]);
            auto it2 = upper_bound(mp2.begin(), mp2.end(), nums[i]);
            int cnt1 = mp1.end() - it1;
            int cnt2 = mp2.end() - it2;
            if (cnt1 > cnt2)
            {
                arr1.emplace_back(nums[i]);
                mp1.insert(it1, nums[i]);
            }
            else if (cnt1 < cnt2)
            {
                arr2.emplace_back(nums[i]);
                mp2.insert(it2, nums[i]);
            }
            else
            {
                if (arr1.size() <= arr2.size())
                {
                    arr1.emplace_back(nums[i]);
                    mp1.insert(it1, nums[i]);
                }
                else
                {
                    arr2.emplace_back(nums[i]);
                    mp2.insert(it2, nums[i]);
                }
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
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
    vector<int> a = {5, 14, 3, 1, 2};
    solution.resultArray(a);
    return 0;
}