#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     *
     * 返回这个最短路径的所有时间点，如果没有路径或者最短路径不止一条，那么返回空
     * @param input_map int整型 vector<vector<>> 输入地图，二维数组，0表示不可达（不考虑负数）
     * @return int整型vector
     */
    using ll = long long;
    struct Node
    {
        int x, y;
        ll dis;
        // Node(int _x, int _y, ll _dis) : x(_x), y(_y), dis(_dis) {}
        bool operator<(const Node &p) const
        {
            return dis > p.dis;
        }
    };

    const ll INT_LL = 0x3f3f3f3f3f3f3f3f;
    int n, m;
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    vector<vector<bool>> vis;
    vector<vector<ll>> dis;
    vector<vector<ll>> count;
    priority_queue<Node> q;
    vector<int> CheckShortestPathOnlyOne(vector<vector<int>> &input_map)
    {
        n = input_map.size();
        m = input_map[0].size();
        vis.resize(n, vector<bool>(m, false));
        dis.resize(n, vector<ll>(m, INT_LL));
        count.resize(n, vector<ll>(m, 0));

        count[0][0] = 1;
        dis[0][0] = input_map[0][0];
        q.push({0, 0, dis[0][0]});
        while (q.size())
        {
            auto out = q.top();
            q.pop();
            if (vis[out.x][out.y])
                continue;
            // cout << out.x << ", " << out.y << endl;
            vis[out.x][out.y] = true;
            for (int i = 0; i < 8; ++i)
            {
                int newx = out.x + dx[i];
                int newy = out.y + dy[i];
                if (newx < 0 || newx >= n || newy < 0 || newy >= m || input_map[newx][newy] == 0)
                    continue;
                if (dis[newx][newy] > out.dis + input_map[newx][newy])
                {
                    dis[newx][newy] = out.dis + input_map[newx][newy];
                    count[newx][newy] = count[out.x][out.y];
                    q.push({newx, newy, dis[newx][newy]});
                }
                else if (dis[newx][newy] == out.dis + input_map[newx][newy])
                {
                    count[newx][newy] += count[out.x][out.y];
                }
            }
        }

        vector<int> ans;
        if (count[n - 1][m - 1] != 0)
        {
            ans.emplace_back(count[n - 1][m - 1]);
            ans.emplace_back(dis[n - 1][m - 1]);
        }
        return ans;
    }
};
int main()
{
    Solution solution;
    vector<vector<int>> a = {{0}};
    for(auto& x: solution.CheckShortestPathOnlyOne(a)) {
        cout << x << endl;
    }
    return 0;
}