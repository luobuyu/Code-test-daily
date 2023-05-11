class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0)
            return -1;
        int tmp = 1, ans = 0;
        for (int i = 0; i < k; ++i)
        {
            ans = (ans + tmp) % k;
            tmp = tmp * 10 % k;
            if (ans == 0)
                return i + 1;
        }
        return -1;
    }
};