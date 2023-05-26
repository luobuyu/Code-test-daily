bool ans[maxn];
int dfn[maxn], low[maxn], dfn_clock = 0;
void tarjan(int u, int fa, bool isRoot)
{
    low[u] = dfn[u] = ++dfn_clock;
    int child_cnt = 0;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if (!dfn[v])
        {
            tarjan(v, u, false);
            low[u] = min(low[u], low[v]);
            if (!isRoot && low[v] >= dfn[u])
                ans[u] = true;
            ++child_cnt;
        }
        else
        {
            if (v != fa)
                low[u] = min(low[u], dfn[v]);
        }
    }
    if (isRoot && child_cnt >= 2)
        ans[u] = true;
}