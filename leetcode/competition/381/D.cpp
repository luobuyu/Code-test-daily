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
    const static int maxn = 5e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int Next[maxn];
    void getNext(string substr, int l2) // 模式串，长度
    {
        Next[0] = -1;
        for (int t = -1, i = 0; i < l2; Next[++i] = ++t)
            for (; ~t && substr[i] != substr[t]; t = Next[t])
                ;
    }
    vector<int> kmp(string str, int l1, string substr, int l2) // 主串，长度  模式串，长度
    {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < l1)
        {
            if (j == -1 || str[i] == substr[j])
                i++, j++;
            else
                j = Next[j];
            if (j == l2)
            {
                ans.emplace_back(i - l2 + 1);
                i--;
                j--;
                j = Next[j];
            }
        }
        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        int lena = a.length(), lenb = b.length();
        int n = s.length();
        getNext(a, lena);
        vector<int> equa = kmp(s, n, a, lena);
        memset(Next, 0, sizeof(Next));
        getNext(b, lenb);
        vector<int> equb = kmp(s, n, b, lenb);
        vector<int> ans;
        int l = 0, r = 0;
        n = equb.size();
        if (equb.size() == 0)
            return {};
        for (auto &x : equa)
        {
            while (l < n && x - equb[l] < k)
                ++l;
            while (r < n && equb[r] - x <= k)
                ++r;
            if (l == r && r == n)
                break;
            if (r >= l)
            {
                ans.emplace_back(x);
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

    return 0;
}