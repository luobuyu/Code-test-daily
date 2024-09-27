#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @param k int整型
     * @return int整型
     */
    int n;
    int maxk;
    bool check(int mid, string &s)
    {
        int i = 0;
        int tot = 0;
        while (i < n)
        {
            if (s[i] == '0')
            {
                ++i;
                continue;
            }
            int j = i;
            int cnt = 0;
            while (j < n && s[j] == '1')
            {
                ++j;
                ++cnt;
                if (cnt > mid)
                {
                    cnt = 0;
                    tot++;
                }
            }
            i = j;
        }
        return tot <= maxk;
    }
    int maxLen(string s, int k)
    {
        n = s.length();
        maxk = k;
        int l = 0, r = n;
        int ans = INT_MAX;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid, s))
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};