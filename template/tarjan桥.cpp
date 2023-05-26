int dfn[maxn], low[maxn], dfn_clock = 0;
void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++dfn_clock;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
            {
                ans = min(ans, w);
            }
        }
        else if (v != fa)
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}