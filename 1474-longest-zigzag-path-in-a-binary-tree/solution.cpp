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
    int result = 0;

    void dfs(TreeNode* root, int depth, bool right) {
        if (!root) return;
        result = max(result, depth);
        if (root->right) dfs(root->right, right && depth ? depth + 1 : 1, false);
        if (root->left) dfs(root->left, !right && depth ? depth + 1 : 1, true);
    }

public:
    int longestZigZag(TreeNode* root) {
        dfs(root, 0, true);
        return result;
    }
};
