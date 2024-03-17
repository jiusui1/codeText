/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        queue<TreeNode *> que;
        if (root != nullptr)
            que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (node->val == p->val or node->val == q->val)
                return node;
            if (node->left != nullptr)
                que.push(node->left);
            if (node->right != nullptr)
                que.push(node->right);
        }
        return nullptr;
    }
};