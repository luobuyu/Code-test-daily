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

struct Trie
{
    static const int M = 26; // 字符集大小
    const static int maxn = (2 + 10) * M;
    int nex[maxn][M], cnt = 0, val[maxn]; // cnt记录点号
    bool exist[maxn];
    void ins(string s)
    {
        int now = 0, len = s.length(); // 下标从1开始
        for (int i = 0; i < len; i++)
        {
            int c = s[i] - 'a';
            if (!nex[now][c])
                nex[now][c] = ++cnt;
            now = nex[now][c];
            ++val[now]; // 记录该前缀的数量
        }
        exist[now] = 1;
    }

    bool find(string &s)
    {
        int now = 0;
        for (int i = s.size() - 1; i >= 0 && s.size() - i <= 200; i--)
        {
            int c = s[i] - 'a';
            if (!nex[now][c])
                return false;

            now = nex[now][c];
            if (exist[now])
                return true;
        }
        // return exist[now];
    }
};
class StreamChecker
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;
    string s;
    Trie tree;
    StreamChecker(vector<string> &words)
    {

        for (int i = 0; i < words.size(); ++i)
        {
            reverse(words[i].begin(), words[i].end());
            tree.ins(words[i]);
        }
    }

    bool query(char letter)
    {
        s.push_back(letter);
        return tree.find(s);
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
    vector<string> a;
    a.push_back("cd");
    a.push_back("f");
    a.push_back("kl");
    StreamChecker streamChecker(a);
    cout << streamChecker.query('a') << endl; // 返回 False
    cout << streamChecker.query('b') << endl; // 返回 False
    streamChecker.query('c');                 // 返回n False
    streamChecker.query('d');                 // 返回 True ，因为 'cd' 在 words 中
    streamChecker.query('e');                 // 返回 False
    streamChecker.query('f');                 // 返回 True ，因为 'f' 在 words 中
    streamChecker.query('g');                 // 返回 False
    streamChecker.query('h');                 // 返回 False
    streamChecker.query('i');                 // 返回 False
    streamChecker.query('j');                 // 返回 False
    streamChecker.query('k');                 // 返回 False
    streamChecker.query('l');                 // 返回 True ，因为 'kl' 在 words 中

    return 0;
}