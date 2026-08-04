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
private:
    void dfs(TreeNode* root, string candidate, vector<string>& result) {
        if (!root) return;
        if (!root->left && !root->right) {
            result.push_back(candidate + to_string(root->val));
            return;
        }
        candidate += to_string(root->val) + "->";
        dfs(root->left, candidate, result);
        dfs(root->right, candidate, result);
        return;
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string candidate = "";
        dfs(root, candidate, result);
        return result;
    }
};
