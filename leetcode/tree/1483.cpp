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
class TreeAncestor
{
public:
    static const int maxn = 1e1 + 1;
    int fa[maxn][18] = {};
    int log2[maxn];
    TreeAncestor(int n, vector<int> &parent)
    {
        log2[0] = log2[1] = 0;
        for (int i = 2; i <= n; ++i)
        {
            log2[i] = log2[i >> 1] + 1;
        }
        for (int i = 0; i < n; ++i)
        {
            fa[i][0] = parent[i];
        }
        for (int i = 0; i < n; ++i)
        {

            for (int j = 1; j <= 17; ++j)
            {
                if (fa[i][j - 1] == -1)
                    fa[i][j] = -1;
                else
                    fa[i][j] = fa[fa[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        int tmp = log2[k], pa = node;
        while (k)
        {
            pa = fa[pa][tmp];
            if (pa == -1)
                break;
            k -= (1 << tmp);
            tmp = log2[k];
        }
        return pa;
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
    vector<int> parent = {-1, 0, 0, 5, 1, 1, 5};
    TreeAncestor solution(7, parent);
    cout << solution.getKthAncestor(3, 2) << endl;
    return 0;
}