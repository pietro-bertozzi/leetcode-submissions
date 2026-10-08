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
    void dfs(TreeNode* root, int targetSum, vector<int>& candidate, vector<vector<int>>& result) {
        if (!root) return;
        candidate.push_back(root->val);
        if (!root->left && !root->right) {
            if (targetSum == root->val) {
                result.push_back(candidate);
            }
        } else {
            dfs(root->left, targetSum - root->val, candidate, result);
            dfs(root->right, targetSum - root->val, candidate, result);
        }
        candidate.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> candidate;
        dfs(root, targetSum, candidate, result);
        return result;
    }
};
