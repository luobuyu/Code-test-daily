int dfn[maxn], low[maxn], dfn_clock = 0;
int st[maxn], top = -1;
bool vis[maxn];
int scc_id[maxn], scc_cnt = 0;

void tarjan(int u)
{
    dfn[u] = low[u] = ++dfn_clock;
    vis[u] = true;
    st[++top] = u;
    for (int i = 0; i < g1[u].size(); ++i)
    {
        int v = g1[u][i];
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        }
        else
        {
            if (vis[v])
                low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u])
    {
        ++scc_cnt;
        while (true)
        {
            scc_id[st[top]] = scc_cnt;
            vis[st[top]] = false;
            value2[scc_cnt] += value1[st[top]];
            if (st[top--] == u)
                break;
        }
    }
}
