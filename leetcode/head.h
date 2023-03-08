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
