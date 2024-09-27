#include <bits/stdc++.h>

using namespace std;


struct ListNode {
	int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(nullptr) {}
};

const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
long long qpow(long long a, long long b)
{
    long long ans = 1, tmp = a;
    while (b)
    {
        if (b & 1)
            ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;
        b >>= 1;
    }
    return ans;
}

long long ifac[maxn]; // 阶乘 逆元
long long fac[maxn];  // 阶乘
auto init = [](int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    ifac[n] = qpow(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; --i)
    {
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    }
    return 0;
}(1e5);

long long Cnm(long long n, long long m)
{
    return fac[n] * ifac[m] % mod * ifac[n - m];
}

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param colors string字符串
     * @return int整型
     */

    int getMethod(ListNode *head, string colors)
    {
        // write code here
        long long curSum = 0;
        ListNode *cur = head;
        int index = 0;
        int odd = 0;  // 偶数
        int even = 0; // 奇数
        while (cur)
        {
            if (colors[index] == 'R')
                curSum += cur->val;
            else
            {
                if (cur->val & 1)
                    even++;
                else
                    odd++;
            }
            cur = cur->next;
            index++;
        }
        if (curSum & 1)
        {
            // 如果当前和是奇数
            long long sum1 = 0;
            // cout << even << " " << odd << endl;
            for (int i = 1; i <= even; i += 2)
            {
                sum1 = (sum1 + Cnm(even, i)) % mod;
            }
            long long sum2 = qpow(2, odd);
            return sum1 * sum2 % mod;
        }
        else
        {
            // 如果当前和是偶数
            long long sum1 = 0;
            for (int i = 0; i <= even; i += 2)
            {
                sum1 = (sum1 + Cnm(even, i)) % mod;
            }
            long long sum2 = qpow(2, odd);
            return sum1 * sum2 % mod;
        }
    }
};

int main()
{

    return 0;
}