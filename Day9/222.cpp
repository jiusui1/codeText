/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    int countNodes(TreeNode *root) {
        queue<TreeNode *> que;
        if (root == nullptr)
            return 0;
        que.push(root);
        int num = 0;
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            num++;
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        return num;
    }
};