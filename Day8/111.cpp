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
    int getDepth(TreeNode *node) {
        if (node == nullptr)
            return 0;
        if (node->left == nullptr and node->right != nullptr)
            return 1 + getDepth(node->right);
        if (node->left != nullptr and node->right == nullptr)
            return 1 + getDepth(node->left);
        int depth = 1 + min(getDepth(node->left), getDepth(node->right));
        return depth;
    }

    int minDepth(TreeNode *root) {
        return getDepth(root);
    }
};