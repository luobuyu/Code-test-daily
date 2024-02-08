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
    string getLen(string a, string b)
    {
        if (a.length() >= b.length())
        {
            int tmp = b.length();
            for (int i = 0; i + tmp < a.length(); ++i)
            {
                if (a.substr(i, tmp) == b)
                {
                    return a;
                }
            }
        }
        int la = a.length(), lb = b.length();
        string ab = a + b;
        for (int i = min(a.length(), b.length()); i > 0; --i)
        {
            string tmpa = a.substr(la - i, i);
            string tmpb = b.substr(0, i);
            if (tmpa == tmpb)
            {
                ab = a + b.substr(i);
                break;
            }
        }
        return ab;
    }
    string getLen(string a, string b, string c)
    {
        string ab = getLen(a, b);
        return getLen(ab, c);
    }
    string minimumString(string a, string b, string c)
    {
        string ans = a + b + c;
        vector<string> tmp = {a, b, c};
        vector<int> id = {0, 1, 2};
        do
        {
            string s = getLen(tmp[id[0]], tmp[id[1]], tmp[id[2]]);
            // cout << id[0] << ", " << id[1] << ", " << id[2] << ", " << s << endl;
            if (s.length() < ans.length())
            {
                ans = s;
            }
            else if (s.length() == ans.length())
            {
                ans = min(ans, s);
            }
        } while (next_permutation(id.begin(), id.end()));
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
    solution.minimumString("a", "bb", "bb");
    return 0;
}