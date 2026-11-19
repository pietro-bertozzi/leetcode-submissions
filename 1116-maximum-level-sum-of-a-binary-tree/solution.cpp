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
    int maxLevelSum(TreeNode* root) {
        int best = INT_MIN, ibest = 1, level = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size(), candidate = 0;
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                candidate += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (candidate > best) {
                best = candidate;
                ibest = level;
            }
            level++;
        }
        return ibest;
    }
};
