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
    int findBottomLeftValue(TreeNode *root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> que;
        que.push(root);
        int ret = 0;
        while (!que.empty()) {
            int size = que.size();
            queue<int> q;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                q.push(node->val);
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            ret = q.front();
        }
        return ret;
    }
};