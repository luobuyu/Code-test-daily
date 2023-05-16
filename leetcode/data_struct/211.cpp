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
class WordDictionary
{
public:
    const static int M = 26;
    const static int maxn = 25 * M + 10;
    int next[maxn][M] = {};
    bool exist[maxn] = {};
    int cnt;
    WordDictionary()
    {
        cnt = 0;
    }

    void addWord(string word)
    {
        int cur = 0;
        cout << word << ", " << word.size() << ", " << cnt << endl;
        for (int i = 0; i < word.size(); ++i)
        {
            int ch = word[i] - 'a';
            if (!next[cur][ch])
                next[cur][ch] = ++cnt;
            cur = next[cur][ch];
        }
        exist[cur] = true;
    }

    bool search(string word)
    {
        int n = word.size();
        return dfs(0, 0, n, word);
    }

    bool dfs(int cur, int step, int &n, string &s)
    {
        if (step == n)
        {
            return exist[cur];
        }
        if (s[step] == '.')
        {
            for (int i = 0; i < M; ++i)
            {
                if (next[cur][i])
                {
                    if (dfs(next[cur][i], step + 1, n, s))
                        return true;
                }
            }
        }
        else
        {
            int ch = s[step] - 'a';
            if (!next[cur][ch])
                return false;
            if (dfs(next[cur][ch], step + 1, n, s))
                return true;
        }
        return false;
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
    WordDictionary solution;
    string s;
    while (cin >> s)
    {
        solution.addWord(s);
    }
    return 0;
}