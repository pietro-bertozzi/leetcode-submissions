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
private:
    unordered_map<TreeNode*, TreeNode*> parent;

    void dfs(TreeNode* node) {
        if (!node) return;
        if (node->left) {
            parent[node->left] = node;
            dfs(node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            dfs(node->right);
        }
    }

    vector<int> bfs(TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        while (!q.empty()) {
            if (!k--) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parent.count(node) && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }
        return {};
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent.clear();
        dfs(root);
        return bfs(target, k);
    }
};
