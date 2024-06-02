#include <bits/stdc++.h>

using namespace std;

 struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return TreeNode类
     */
    TreeNode *create(int n)
    {
        int sum = pow(2, n - 1);
        int cnt = 1;
        queue<TreeNode *> q;
        TreeNode *cur = new TreeNode(sum);
        if (n == 1)
            return cur;
        q.push(cur);
        int tot = 1;
        while (q.size())
        {
            int size = q.size();
            cnt = sum;
            for (int i = 0; i < size; ++i)
            {
                auto fa = q.front();
                q.pop();
                fa->left = new TreeNode(1);
                cnt--;
                if (i == size - 1)
                {
                    fa->right = new TreeNode(cnt);
                }
                else
                {
                    fa->right = new TreeNode(1);
                    cnt--;
                }
                q.push(fa->left);
                q.push(fa->right);
            }
            tot++;
            if (tot == n)
                break;
        }
        return cur;
    }
};
int main()
{

    return 0;
}