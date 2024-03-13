#ifndef _LEETCODE_HEAD_H_
#define _LEETCODE_HEAD_H_
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(vector<int> &nums)
{
    ListNode *virHead = new ListNode();
    ListNode *pre = virHead;
    for (auto &num : nums)
    {
        ListNode *p = new ListNode(num, nullptr);
        pre->next = p;
        pre = p;
    }
    return virHead->next;
}
// class Node
// {
// public:
//     int val;
//     Node *next;
//     Node *random;

//     Node(int _val)
//     {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

void show(ListNode *head)
{
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
}
void show()
{
}
#endif
