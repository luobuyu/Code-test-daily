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

class Solution
{
public:
    // 最大堆，小于中位数的
    // 最小堆。大于等于中位数的
    // size1 >= size2
    priority_queue<int> qMax;
    priority_queue<int, vector<int>, greater<int>> qMin;
    void Insert(int num)
    {
        if (qMax.size() == qMin.size())
        {
            qMin.push(num);
            qMax.push(qMin.top());
            qMin.pop();
        }
        else
        {
            qMax.push(num);
            qMin.push(qMax.top());
            qMax.pop();
        }
    }

    double GetMedian()
    {
        if (qMin.size() == qMax.size())
        {
            return (qMin.top() + qMax.top()) / 2.0;
        }
        else
        {
            return qMax.top();
        }
    }
};