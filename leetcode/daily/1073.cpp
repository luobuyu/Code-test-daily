// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
int t, n, m, k;
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
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> ans;
        int add = 0, i, j, tmp, a, b;
        for (i = arr1.size() - 1, j = arr2.size() - 1; i >= 0 || j >= 0 || add; --i, --j)
        {
            a = (i >= 0 ? arr1[i] : 0);
            b = (j >= 0 ? arr2[j] : 0);
            tmp = a + b + add;
            if (tmp >= 2)
            {
                add = -(tmp / 2);
                tmp = tmp % 2;
            }
            else if (tmp == -1)
            {
                tmp = 1;
                add = 1;
            }
            else
                add = 0;
            ans.emplace_back(tmp);
        }
        i = ans.size() - 1;
        while (i > 0 && ans[i] == 0)
            i--;
        ans.resize(i + 1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<int> arr1 = {1};
    vector<int> arr2 = {1};
    for (auto &u : solution.addNegabinary(arr1, arr2))
        cout << u << ", ";
    cout << endl;
    return 0;
}