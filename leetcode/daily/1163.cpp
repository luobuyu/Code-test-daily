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
    const static int maxn = 4e5 + 10;
    int sa[maxn], wa[maxn], wb[maxn], bucket[maxn];
    // wa 第一关键字， wb 第二关键字
    string s;

    int rk[maxn], height[maxn];
    void getHeight(int n)
    {
        int k = 0;
        for (int i = 0; i < n; i++)
            rk[sa[i]] = i + 1; // 之前只得到了sa，还没有搞rk
        for (int i = 0; i < n; i++)
        {
            if (rk[i] == 1)
                continue; // height[1] = 0;
            if (k)
                --k;
            int j = sa[rk[i] - 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            height[rk[i]] = k;
        }
    }

    void getSA(int n, int m = 130)
    {
        int *x = wa, *y = wb;
        for (int i = 0; i <= m; i++)
            bucket[i] = 0; // 桶
        for (int i = 0; i < n; i++)
            bucket[x[i] = s[i] - 'a' + 1]++;
        for (int i = 1; i <= m; i++)
            bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; i--)
            sa[--bucket[x[i]]] = i;
        // 赋上编号, 排名 获得 编号
        for (int k = 1; k <= n; k <<= 1) // p用来计数最大排名，排名全部不同的时候跳出循环
        {
            int p = 0;
            // y[i] 表示第二关键字排名为i的数，第一关键字的位置
            // 第n-k+1到第n位是没有第二关键字的 所以排名在最前面
            for (int i = n - k; i < n; i++)
                y[p++] = i;
            for (int i = 0; i < n; i++)
                if (sa[i] >= k)
                    y[p++] = sa[i] - k; // 排名为i的数 在数组中是否在第k位以后
            // 如果满足(sa[i]>k) 那么它可以作为别人的第二关键字，就把它的第一关键字的位置添加进y就行了
            // 所以i枚举的是第二关键字的排名，第二关键字靠前的先入队

            // 按照第二关键字排序
            for (int i = 0; i <= m; i++)
                bucket[i] = 0; // 初始化桶

            for (int i = 0; i < n; i++)
                bucket[x[y[i]]]++;
            for (int i = 1; i <= m; i++)
                bucket[i] += bucket[i - 1];
            for (int i = n - 1; i >= 0; i--)
                sa[--bucket[x[y[i]]]] = y[i]; // 第一关键字相同时，第二关键字，第二关键字较大的这个后缀的排名是啥到了排名，我们也就能更新sa了
                                              // 因为y的顺序是按照第二关键字的顺序来排的
            // 第二关键字靠后的，在同一个第一关键字桶中排名越靠后
            // 基数排序
            swap(x, y);
            x[sa[0]] = 0;
            p = 1;
            for (int i = 1; i < n; i++)
                x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? p - 1 : p++; // 更新排名
            if (p >= n)
                break;
            m = p;
        }
        // 注意最后输出的时候需要输出 sa[i] + 1
        getHeight(n);
    }
    string lastSubstring(string ss)
    {
        s = ss;
        int n = s.length();
        getSA(n, 26);
        return s.substr(sa[n - 1]);
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
    string s = "abab";
    cout << solution.lastSubstring(s) << endl;
    return 0;
}