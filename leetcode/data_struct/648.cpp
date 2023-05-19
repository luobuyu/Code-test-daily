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
    struct TrieNode
    {
        const static int M = 26;
        TrieNode **next;
        bool exist;
        int val;
        TrieNode()
        {
            next = new TrieNode *[M]();
            for (int i = 0; i < M; ++i)
                next[i] = nullptr;
            exist = false;
            val = 0;
        }
    };
    struct Trie
    {
        TrieNode *root;
        Trie()
        {
            root = new TrieNode();
        }
        void insert(string &s)
        {
            TrieNode *cur = root;
            for (int i = 0; i < s.length(); ++i)
            {
                int ch = s[i] - 'a';
                if (!cur->next[ch])
                    cur->next[ch] = new TrieNode();
                cur = cur->next[ch];
                cur->val++;
            }
            cur->exist = true;
        }
        string search(string &s)
        {
            TrieNode *cur = root;
            for (int i = 0; i < s.size(); ++i)
            {
                int ch = s[i] - 'a';
                if (!cur->next[ch])
                    break;
                cur = cur->next[ch];
                if (cur->exist)
                    return s.substr(0, i + 1);
            }
            return s;
        }
    };

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie trie;
        for (auto &s : dictionary)
            trie.insert(s);
        string ans;
        int l = 0, r = 0, n = sentence.size();
        while (l < n)
        {
            while (r < n && sentence[r] != ' ')
                ++r;
            string word = sentence.substr(l, r - l);
            ans.append(trie.search(word));
            if (r < n)
                ans.push_back(' ');
            l = r + 1;
            r = l;
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
    vector<string> s = {"cat", "bat", "rat"};
    solution.replaceWords(s, "the cattle was rattled by the battery");
    return 0;
}