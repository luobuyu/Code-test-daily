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
struct Trie
{
    struct TrieNode
    {
        vector<TrieNode *> next;
        bool exist;
        TrieNode() : next(26, nullptr), exist(false) {}
    };
    TrieNode *root;
    TrieNode *streamCur;
    Trie()
    {
        root = new TrieNode();
        streamCur = nullptr;
    }
    void insert(const string &word)
    {
        TrieNode *cur = root;
        int n = word.size();
        for (int i = 0; i < n; ++i)
        {
            int index = word[i] - 'a';
            if (!cur->next[index])
                cur->next[index] = new TrieNode();
            cur = cur->next[index];
        }
        cur->exist = true;
    }
    void initStreamQuery()
    {
        streamCur = root;
    }
    bool queryStream(char ch)
    {
        if (streamCur == nullptr || streamCur->next[ch - 'a'] == nullptr)
        {
            // next 不存在的时候需要清空一下，否则会出错，比如 leetscode， leet在，next[s] 不在，如果不清空，接下来 c 会判定在。
            streamCur = nullptr;
            return false;
        }
        streamCur = streamCur->next[ch - 'a'];
        return streamCur->exist;
    }
};
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int minExtraChar1(string s, vector<string> &dictionary)
    {
        unordered_set<string> ss;
        for (auto &s : dictionary)
            ss.insert(s);
        int n = s.length();
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j < i; ++j)
            {
                // [j + 1, i]
                string tmp = s.substr(j + 1 - 1, i - j);
                if (ss.count(tmp))
                {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
    }

    int minExtraChar(string s, vector<string> &dictionary)
    {
        Trie trie;
        for (auto &s : dictionary)
        {
            reverse(s.begin(), s.end());
            trie.insert(s);
        }
        int n = s.length();
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + 1;
            trie.initStreamQuery();
            for (int j = i - 1; j >= 0; --j)
            {
                if (trie.queryStream(s[j]))
                {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
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