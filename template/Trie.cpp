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
            cur->val++;
        }
        cur->exist = true;
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
};