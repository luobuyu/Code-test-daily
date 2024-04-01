#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
int n, m, q, k;

struct ListNode {
	int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return bool布尔型vector
     */
    bool check(ListNode *head)
    {
        if (head == nullptr)
            return true;
        ListNode *cur = head;
        int cnt = 0;
        while (cur->next)
        {
            if (cur->val > cur->next->val)
            {
                ++cnt;
            }
            cur = cur->next;
        }
        if (cnt == 0)
            return true;
        if (cnt >= 2)
            return false;
        return cur->val < head->val;
    }
    vector<bool> canSorted(vector<ListNode *> &lists)
    {
        vector<bool> ans;
        for (auto &h : lists)
        {
            if (check(h))
                ans.emplace_back(true);
            else
                ans.emplace_back(false);
        }
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    return 0;
}