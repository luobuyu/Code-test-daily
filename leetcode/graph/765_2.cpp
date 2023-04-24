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
    return 0;
}();
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;
    int ans = 0;
    void dfs(int step, int n, vector<bool> &flag, vector<int> &row)
    {
        if (step >= n)
            return;
        int nex = step + 1;
        if (flag[nex] == true)
        {
            dfs(step + 2, n, flag, row);
        }
        else
        {
            for (int i = nex + 1; i < n; ++i)
            {
                if ((row[step] ^ row[i]) == 1)
                {
                    swap(row[nex], row[i]);
                    ans++;
                    flag[nex] = true;
                    if ((row[i] ^ row[i ^ 1]) == 1)
                    {
                        flag[i] = flag[i ^ 1] = true;
                    }
                    dfs(step + 2, n, flag, row);
                }
            }
        }
    }
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size();
        vector<bool> flag(n);
        for (int i = 0; i < n; i = i + 2)
        {
            flag[i] = true;
            flag[i + 1] = ((row[i] ^ row[i + 1]) == 1);
        }
        dfs(0, n, flag, row);
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
    vector<int> a = {2, 0, 5, 4, 3, 1};
    cout << solution.minSwapsCouples(a) << endl;
    return 0;
}