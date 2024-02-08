class Median
{
private:
    const static int mod = 1e9 + 7;
    priority_queue<int> left;                             // 堆顶是最大值，小于中位数的
    priority_queue<int, vector<int>, greater<int>> right; // 堆顶是最小值，大于等于中位数的
public:
    int leftSum;
    int rightSum;
    Median() : leftSum(0), rightSum(0) {}
    vector<int> getNum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            push(nums[i]);
            ans[i] = getMedian();
        }
        return ans;
    }
    void push(int x)
    {
        // 如果两个堆大小相等
        if (left.size() == right.size())
        {
            // 加入right
            if (left.empty() || x >= left.top())
            {
                right.push(x);
                rightSum = (rightSum + x) % mod;
            }
            else
            {
                // left弹出最大的到right，加入left
                right.push(left.top());
                leftSum = (leftSum + x - left.top()) % mod;
                rightSum = (rightSum + left.top()) % mod;
                left.pop();
                left.push(x);
            }
        }
        else // left.size() + 1 == right.size()
        {
            if (x <= right.top())
            {
                left.push(x);
                leftSum = (leftSum + x) % mod;
            }
            else
            {
                left.push(right.top());
                leftSum = (leftSum + right.top()) % mod;
                rightSum = (rightSum + x - right.top()) % mod;
                right.pop();
                right.push(x);
            }
        }
    }
    int getMedian()
    {
        return right.top();
    }
};