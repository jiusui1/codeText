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
    vector<int> largestValues(TreeNode *root) {
        queue<TreeNode *> que;
        vector<int> res;
        if (root != nullptr)
            que.push(root);
        while (!que.empty()) {
            int size = que.size();
            auto maxVal = INT_MIN;
            while (size--) {
                auto node = que.front();
                que.pop();
                maxVal = maxVal > node->val ? maxVal : node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            res.push_back(maxVal);
        }
        return res;
    }
};