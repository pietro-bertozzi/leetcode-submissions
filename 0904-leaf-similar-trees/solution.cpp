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
    void getSequence(TreeNode* root, vector<int>& v) {
        if (!root) return;
        if (!root->left && !root->right) {
            v.push_back(root->val);
            return;
        }
        getSequence(root->left, v);
        getSequence(root->right, v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        getSequence(root1, v1);
        getSequence(root2, v2);
        return v1 == v2;
    }
};
