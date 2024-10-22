#include <bits/stdc++.h>


using namespace std;

class Solution
{
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     *
     * 输入一个整数数组，判断这个整数数组是否可分
     * @param input_array int整型 vector 整数数组
     * @return bool布尔型
     */
    using ll = long long;
    bool checkArray(vector<int> &input_array)
    {
        int n = input_array.size();
        int sum = 0;
        int minx = 0;
        for (auto &x : input_array)
        {
            sum += x;
            minx = min(minx, x);
        }
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        // 背包问题，dp[sum / 2];
        unordered_set<int> dp;
        dp.insert(0);
        // dp[i][j] = dp[i - 1][j - v] + a[i];
        for (int i = 0; i < n; ++i)
        {
            unordered_set<int> newdp = dp;
            for(int tmp: dp) {
                newdp.insert(tmp + input_array[i]);
            }
            dp = newdp;
        }
        return dp.count(target) > 0;
    }
};

int main()
{
    Solution solution;
    vector<int> a = {0};
    cout << solution.checkArray(a) << endl;
    return 0;
}