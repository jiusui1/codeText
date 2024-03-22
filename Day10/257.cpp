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
    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<string> res;
        string path = to_string(root->val);
        dfs(root, path, res);
        return res;
    }

   private:
    void dfs(TreeNode *root, string path, vector<string> &res) {
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }
        if (root->left != nullptr) {
            dfs(root->left, path + "->" + to_string(root->left->val), res);
        }
        if (root->right != nullptr) {
            dfs(root->right, path + "->" + to_string(root->right->val), res);
        }
    }
};
