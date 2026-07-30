class Solution {
private:
    unordered_map<long long, int> prefixSumCount;

    int dfs(TreeNode* node, long long currentSum, int targetSum) {
        if (!node) return 0;
        currentSum += node->val;
        int count = prefixSumCount[currentSum - targetSum];
        prefixSumCount[currentSum]++;
        count += dfs(node->left, currentSum, targetSum);
        count += dfs(node->right, currentSum, targetSum);
        prefixSumCount[currentSum]--;
        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        prefixSumCount.clear();
        prefixSumCount[0] = 1;
        return dfs(root, 0, targetSum);
    }
};
