struct UF
{
    vector<int> fa;
    int count;
    UF(int n) : fa(n), count(n)
    {
        for (int i = 0; i < n; ++i)
            fa[i] = i;
    }
    int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
    void unite(int u, int v)
    {
        int up = find(u), vp = find(v);
        if (up != vp)
        {
            fa[up] = vp;
            count--;
        }
    }
    bool connect(int u, int v) { return find(u) == find(v); }
    int getCount() { return count; }
};