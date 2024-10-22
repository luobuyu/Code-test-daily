/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号
子串
的长度。

示例 1：
输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"

示例 2：
输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
()()
(()(
(())
)())
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int checkString(string s)
    {
        stack<int> st; // 存 index;
        st.push(-1);
        // int top = -1;
        // s[++top] = (char)i;
        // s[top];
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == ')')
            {
                if (st.size() != -1 && s[st.top()] == '(')
                {
                    st.pop();
                    if (st.size())
                    {
                        ans = max(ans, i - st.top());
                    }
                }
                else
                {
                    if (st.size())
                    {
                        ans = max(ans, i - st.top() - 1);
                    }
                    st.push(i);
                }
            }
            else
            {
                if (st.size())
                {
                    ans = max(ans, i - st.top() - 1);
                }
                st.push(i);
            }
        }
        if (st.size() == 1)
        {
            ans = max(ans, n - st.top() - 1);
        }
        return ans;
    }
};

int nCm(int n, int m)
{
    if (m > n - m)
        m = n - m;
    int ans = 1;
    for (int i = 1, j = n - m + 1; i <= m; ++i, ++j)
    {
        ans = ans * j / i;
    }
    return ans;
}

int main()
{
    Solution solution;
    // string s = ")()())";
    // cout << solution.checkString(s) << endl;
    cout << nCm(10, 3) << endl;
    return 0;
}