// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{
    static string buf_line;
    static int _i;
    static int _n;
    static char _ch;
    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        _ch = buf_line[_i++];
        while (_ch < '0' || _ch > '9')
        {
            if (_ch == '-')
                flag = -1;
            _ch = buf_line[_i++];
        }
        while (_ch >= '0' && _ch <= '9')
        {
            x = (x << 3) + (x << 1) + (_ch ^ 48), _ch = buf_line[_i++];
        }
        x *= flag;
        return true;
    }

    template <class T, class... _T>
    inline bool read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline bool getline()
    {
        if (!getline(cin, buf_line))
            return false;
        _i = 0, _n = buf_line.length();
        return true;
    }
    template <class T>
    inline void show(T *a, int n)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            cout << a[i];
        }
        cout << "]";
    }

    bool endofl()
    {
        if (_i >= _n)
            return true;
        if (_i == 0)
            return false;
        if (buf_line[_i - 1] == ']')
        {
            _i++;
            return true;
        }
        return false;
    }

    template <class T, std::size_t Num>
    inline void show(T a[][Num], int n, int m)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            show(a[i], m);
        }
        cout << "]";
    }

} // namespace FAST_IO
using namespace FAST_IO;

// int init = []
// {
//     /*********** fast_read ***************/
//     freopen("user.out", "w", stdout);
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     /*************************************/

//     while (true)
//     {
//         if (!getline())
//             break;

//         getline();
//     }
//     exit(0);
//     return 0;
// }();

auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

struct TrieNode
{
    const static int M = 26;
    vector<TrieNode *> next;
    bool exist;
    int val;
    TrieNode() : next(M, nullptr)
    {
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
            // cur->val++;
        }
        cur->exist = true;
        cur->val++;
    }
    TrieNode *insert(string &s, TrieNode *cur)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            int ch = s[i] - 'a';
            if (!cur->next[ch])
                cur->next[ch] = new TrieNode();
            cur = cur->next[ch];
            // cur->val++;
        }
        cur->exist = true;
        cur->val++;
        return cur;
    }
    bool exist(string &s)
    {
        TrieNode *cur = root;
        for (int i = 0; i < s.size(); ++i)
        {
            int ch = s[i] - 'a';
            if (!cur->next[ch])
                return false;
            cur = cur->next[ch];
        }
        return cur->exist;
    }
    int query(string &s)
    {
        TrieNode *cur = root;
        for (int i = 0; i < s.size(); ++i)
        {
            int ch = s[i] - 'a';
            if (!cur->next[ch])
                return false;
            cur = cur->next[ch];
        }
        return cur->val;
    }
};
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    long long mod = 1e9 + 7;
    int base = 1331;
    // 不需要求 Z[0],Z[0] = len
    int Z[maxn];
    void zFunction(const char *str, int len)
    {
        Z[0] = len;
        for (int i = 1, l = 0, r = 0; i < len; ++i)
        {
            if (i <= r && Z[i - l] < r - i + 1)
                Z[i] = Z[i - l];
            else
            {
                Z[i] = max(0, r - i + 1);
                while (i + Z[i] < len && str[Z[i]] == str[i + Z[i]]) // 对多余的需要暴力求出
                    ++Z[i];
            }
            if (i + Z[i] - 1 > r)
                l = i, r = i + Z[i] - 1;
        }
    }
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        Trie trie;
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int len = words[i].length();
            zFunction(words[i].c_str(), len);
            ans += trie.query(words[i]);
            string tmp;
            TrieNode *cur = trie.root;
            for (int j = len - 1; j >= 0; --j)
            {
                tmp.push_back(words[i][len - 1 - j]);
                if (Z[j] == len - j)
                {
                    cur = trie.insert(tmp, cur);
                    tmp.clear();
                }
            }
        }
        return ans;
    }
};

int t, n, m, k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<string> a = {"a", "aba", "ababa", "aa"};
    solution.countPrefixSuffixPairs(a);
    return 0;
}