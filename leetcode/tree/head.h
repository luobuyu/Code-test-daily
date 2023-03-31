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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
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

TreeNode *build_tree(vector<int> &nums)
{
    TreeNode *root;
    queue<TreeNode **> q;
    q.push(&root);
    TreeNode **u;
    for (int i = 0; i < nums.size(); ++i)
    {
        u = q.front();
        q.pop();
        if (nums[i] != -1)
        {
            (*u) = new TreeNode(nums[i]);
            q.push(&((*u)->left));
            q.push(&((*u)->right));
        }
        else
        {
            u = nullptr;
        }
    }
    return root;
}
#endif
