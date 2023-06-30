// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
#define ll long long
#define lll long long
#define PII pair<int, int>
#define LEETCODE
namespace FAST_IO
{
    static string buf_line;
    static int _i;
    static int _n;

    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        char ch = buf_line[_i++];
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = buf_line[_i++];
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = buf_line[_i++];
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
// #ifndef LEETCODE
int init = []
{
    /*********** fast_read ***************/
    freopen("user.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*************************************/
    static const int maxn = 1e5 + 10;
    int ans[2][maxn];
    int upper, lower;
    int n, v;
    int colsum[maxn];
    while (true)
    {
        if (!getline())
            break;
        read(upper);
        getline();
        read(lower);
        getline();
        for (n = 0; read(v); ++n)
            colsum[n] = v;
        for (int i = 0; i < n; ++i)
        {
            ans[0][i] = ans[1][i] = 0;
        }

        int tot0 = 0, tot1 = 0, tot2 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (colsum[i] == 2)
            {
                tot0++;
                tot1++;
                ans[0][i] = 1;
                ans[1][i] = 1;
            }
            else if (colsum[i] == 0)
                ++tot2;
        }
        if (tot0 > upper || tot1 > lower || (upper - tot0 + lower - tot1 < n - tot0 - tot2))
        {
            cout << "[]\n";
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (colsum[i] == 1)
                {
                    if (tot0 < upper)
                    {
                        ans[0][i] = 1;
                        ++tot0;
                    }
                    else
                    {
                        ans[1][i] = 1;
                        ++tot1;
                    }
                }
            }
            if (tot0 != upper || tot1 != lower)
            {
                cout << "[]\n";
            }
            else
            {
                show(ans, 2, n);
                cout << "\n";
            }
        }
    }
    exit(0);
    return 0;
}();
class Solution
{
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
    {
        return vector<vector<int>>();
    }
};
// #endif

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