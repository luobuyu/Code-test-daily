auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        if (firstList.size() == 0 || secondList.size() == 0)
            return {};
        int size1 = firstList.size(), size2 = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < size1 && j < size2)
        {
            int x = max(firstList[i][0], secondList[j][0]);
            int y = min(firstList[i][1], secondList[j][1]);
            if (x <= y)
                ans.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
            if (firstList[i][1] < secondList[j][1])
                ++i;
            else
                ++j;
        }
        return ans;
    }
};