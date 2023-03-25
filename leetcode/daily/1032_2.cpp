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

class StreamChecker
{
    const static int maxn = 2e3 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;
    const static int M = 26;
    struct ACTrie
    {
        int next[maxn][M], cnt = 0, fail[maxn];
        bool exist[maxn];
        queue<int> q;
        int root;
        void insert(string s)
        {
            int now = 0, len = s.length();
            for (int i = 0; i < len; ++i)
            {
                if (!next[now][s[i] - 'a'])
                    next[now][s[i] - 'a'] = ++cnt;
                now = next[now][s[i] - 'a'];
            }
            exist[now] = true;
        }
        void build()
        {
            for (int i = 0, child; i < M; ++i)
            {
                child = next[0][i];
                if (child)
                {
                    fail[child] = 0;
                    q.push(child);
                }
            }
            int u, child;
            while (q.size())
            {
                u = q.front();
                q.pop();
                for (int i = 0; i < M; ++i)
                {
                    child = next[u][i];
                    if (child)
                    {
                        fail[child] = next[fail[u]][i];
                        q.push(child);
                    }
                    else
                        next[u][i] = next[fail[u]][i];
                }
            }
            root = 0;
        }
        bool query(char ch)
        {
            root = next[root][ch - 'a'];
            if (exist[root])
                return true;
            int tmp = root;
            while (tmp != 0)
            {
                tmp = fail[tmp];
                if (exist[tmp])
                {
                    return true;
                }
            }
            return false;
        }
    } trie;

public:
    StreamChecker(vector<string> &words)
    {
        for (int i = 0; i < words.size(); ++i)
        {
            trie.insert(words[i]);
        }
        trie.build();
    }

    bool query(char letter)
    {
        trie.query(letter);
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
    // Solution solution;

    return 0;
}