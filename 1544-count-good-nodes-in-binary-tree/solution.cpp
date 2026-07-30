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
    int dfs(TreeNode* root, int best) {
        if (!root) return 0;
        if (root->val < best) return dfs(root->right, best) + dfs(root->left, best);
        else return 1 + dfs(root->right, root->val) + dfs(root->left, root->val);
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
