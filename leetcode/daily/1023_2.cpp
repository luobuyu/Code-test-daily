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

    struct Trie
    {
        const static int Len = 100 * 30;
        const static int M = 'z' - 'A';
        int nex[Len][M] = {}, cnt = 0;
        bool exist[Len] = {};
        void insert(string s)
        {
            int now = 0;
            for (int i = 0; i < s.length(); ++i)
            {
                int ch = s[i] - 'A';
                if (!nex[now][ch])
                    nex[now][ch] = ++cnt;
                now = nex[now][ch];
            }
            exist[now] = true;
        }

        bool query(string s)
        {
            int now = 0;
            for (int i = 0; i < s.length(); ++i)
            {
                int ch = s[i] - 'A';
                if (nex[now][ch])
                    now = nex[now][ch];
                else if (isupper(s[i]))
                    return false;
                else
                    continue;
            }
            return exist[now];
        }
    };
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        Trie trie;
        trie.insert(pattern);
        vector<bool> ans;
        for (auto &s : queries)
        {
            ans.emplace_back(trie.query(s));
        }
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
    vector<string> s = {
        "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    solution.camelMatch(s, "FoBa");
    return 0;
}