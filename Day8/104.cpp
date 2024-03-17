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
        int leftdepth = getDepth(node->left);
        int rightdepth = getDepth(node->right);
        int depth = 1 + max(leftdepth, rightdepth);
        return depth;
    }
    int maxDepth(TreeNode *root) {
        return getDepth(root);
    }
};