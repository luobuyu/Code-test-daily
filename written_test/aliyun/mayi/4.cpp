#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 统计等比数列的数量
int countGeometricSubarrays(const vector<int> &stars, int left, int right)
{
    if (left == right)
        return 1; // 单个元素的情况

    // 统计左侧和右侧
    int mid = left + (right - left) / 2;
    int count = countGeometricSubarrays(stars, left, mid) + countGeometricSubarrays(stars, mid + 1, right);

    // 处理跨越左右子数组的情况
    // 用一个map记录当前元素的频率
    unordered_map<int, int> freq;

    // 统计左侧元素
    for (int i = left; i <= mid; ++i)
    {
        freq[stars[i]]++;
    }

    // 统计右侧元素
    vector<int> rightPart;
    for (int j = mid + 1; j <= right; ++j)
    {
        rightPart.push_back(stars[j]);
    }

    // 需要检查右侧元素与左侧的结合
    int n = rightPart.size();
    for (int start = 0; start < n; ++start)
    {
        long long ratio = 1; // 记录公比
        int prevValue = rightPart[start];

        for (int end = start; end < n; ++end)
        {
            // 在这里计算公比
            if (start == end)
            {
                count++; // 单个元素
                continue;
            }

            // 确保我们没有出现除以零的情况
            if (prevValue == 0 || rightPart[end] % prevValue != 0)
            {
                break; // 不是整数比，停止扩展
            }
            ratio = rightPart[end] / prevValue;

            // 确保这个比在左侧区间存在
            if (freq.find(prevValue) != freq.end() && freq.find(ratio) != freq.end())
            {
                count++;
            }
            prevValue = rightPart[end];
        }
    }

    return count;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> stars(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> stars[i];
        }

        // 计算总的等比数列子区间数量
        cout << countGeometricSubarrays(stars, 0, n - 1) << endl;
    }

    return 0;
}
