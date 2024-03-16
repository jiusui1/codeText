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
    vector<double> averageOfLevels(TreeNode *root) {
        queue<TreeNode *> que;
        vector<double> res;
        if (root == nullptr)
            return res;
        que.push(root);

        while (!que.empty()) {
            auto size = que.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                auto node = que.front();
                que.pop();
                sum += node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            res.push_back(sum / size);
        }
        return res;
    }
};