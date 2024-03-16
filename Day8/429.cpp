/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
   public:
    vector<vector<int>> levelOrder(Node *root) {
        queue<Node *> que;
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            while (size--) {
                auto node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++) {
                    if (node->children[i])
                        que.push(node->children[i]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};