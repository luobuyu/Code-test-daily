// #pragma GCC optimize(2)"
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
    struct TrieNode
    {
        vector<TrieNode *> children;
        TrieNode *fail;
        bool exist;
        TrieNode()
        {
            children = vector<TrieNode *>(26, nullptr);
            fail = nullptr;
            exist = false;
        }
    };
    TrieNode *root, *tmp;
    void insert(string s)
    {
        root = new TrieNode();
        TrieNode *cur = root;
        for (int i = 0; i < s.length(); ++i)
        {
            if (cur->children[s[i] - 'a'] == nullptr)
            {
                cur->children[s[i] - 'a'] = new TrieNode();
            }
            cur = cur->children[s[i] - 'a'];
        }
        cur->exist = true;
    }
    queue<TrieNode *> q;
    void build()
    {
        for (int i = 0; i < M; ++i)
        {
            if (root->children[i])
            {
                root->children[i]->fail = root;
                q.push(root->children[i]);
            }
        }
        TrieNode *u, *child;
        while (q.size())
        {
            u = q.front();
            q.pop();
            for (int i = 0; i < M; ++i)
            {
                child = u->children[i];
                if (child)
                {
                    child->fail = u->fail->children[i];
                    q.push(child);
                }
                else
                {
                    child = u->fail->children[i];
                }
            }
        }
    }

public:
    StreamChecker(vector<string> &words)
    {
        for (int i = 0; i < words.size(); ++i)
        {
            insert(words[i]);
        }
        build();
    }

    bool query(char ch)
    {
        root = root->children[ch - 'a'];
        if (root->exist)
        {
            return true;
        }
        else
        {
            TrieNode *tmp = root;
            while (tmp)
            {
                tmp = tmp->fail;
                if (tmp->exist)
                {
                    return true;
                }
            }
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
    // Solution solution;

    return 0;
}