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
    int maxDepth(Node *root) {
        queue<Node *> que;
        int depth = 0;
        if (root == nullptr)
            return 0;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                Node *node = que.front();
                que.pop();
                for (int j = 0; j < node->children.size(); j++) {
                    if (node->children[j])
                        que.push(node->children[j]);
                }
            }
        }
        return depth;
    }
};

class solution {
   public:
    int maxDepth(Node *root) {
        if (root == 0)
            return 0;
        int depth = 0;
        for (int i = 0; i < root->children.size(); i++) {
            depth = max(depth, maxDepth(root->children[i]));
        }
        return depth + 1;
    }
};