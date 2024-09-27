#include <bits/stdc++.h>

using namespace std;

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
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *insert0(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *cur = head;
        while (cur->next)
        {
            ListNode *p = new ListNode(0);
            p->next = cur->next;
            cur->next = p;
            cur = p->next;
        }
        return head;
    }
};
int main()
{

    return 0;
}