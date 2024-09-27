// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
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

class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;
    TrieNode()
    {
        fill(begin(children), end(children), nullptr);
        isWord = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (!node->children[idx])
            {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isWord = true;
    }

    // 返回从 target[start:] 可以匹配的所有前缀长度
    vector<int> search(const string &target, int start)
    {
        vector<int> matchLengths;
        TrieNode *node = root;
        for (int i = start; i < target.size(); ++i)
        {
            int idx = target[i] - 'a';
            if (!node->children[idx])
            {
                break;
            }
            node = node->children[idx];
            matchLengths.push_back(i - start + 1);
        }
        return matchLengths;
    }
};

class Solution
{
public:
    const int INF = 0x3f3f3f3f;

    int minValidStrings(vector<string> &words, string target)
    {
        int n = target.size();
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        Trie trie;
        for (const string &word : words)
        {
            trie.insert(word);
        }

        for (int i = 0; i < n; ++i)
        {
            if (dp[i] == INF)
                continue;
            vector<int> matchLengths = trie.search(target, i);
            for (int len : matchLengths)
            {
                if (i + len <= n)
                {
                    dp[i + len] = min(dp[i + len], dp[i] + 1);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
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

    return 0;
}