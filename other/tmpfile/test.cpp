#include <bits/stdc++.h>
using namespace std;
int m, k;
bool point[100005];
vector<int> g[100005];
queue<int> q;
int son[100005];
void dfs(int i)
{
   point[i] = true;
   for (int j = 0; j < g[i].size(); j++)
   {
      int v = g[i][j];
      if (!point[v])
      {
         dfs(v);
      }
   }
}

void dfs(int u, int fa)
{
   for (int i = 0; i < g[u].size(); i++)
   {
      int v = g[u][i];
      if (v != fa)
      {
         dfs(v, u);
      }
   }
}
int num = 0;
void dfs(int i)
{
   point[i] = true;
   num++;
   for (int j = 0; j < g[i].size(); j++)
   {
      int v = g[i][j];
      if (!point[v])
      {
         dfs(v);
      }
   }
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> m >> k;
   for (int i = 0; i < m; i++)
   {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
   }
   dfs(1);
   int cnt = 0;
   for (int i = 1; i <= n; i++)
   {
      cnt += point[i];
   }
   if (cnt != n)
   {
   }
   else
   {
      if (m == n - 1)
      {
      }
   }
}
