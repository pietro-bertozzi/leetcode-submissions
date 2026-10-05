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
    int checkHeight(TreeNode* node) {
        if (!node) return 0;
        int l = checkHeight(node->left);
        if (l == -1) return -1;
        int r = checkHeight(node->right);
        if (r == -1) return -1;
        if (abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
