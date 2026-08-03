class Solution {
private:
    void backtracking(int i, vector<int>& nums, int candidate, int& result) {
        if (i == nums.size()) {
            result += candidate;
            return;
        }
        backtracking(i + 1, nums, candidate ^ nums[i], result);
        backtracking(i + 1, nums, candidate, result);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        backtracking(0, nums, 0, result);
        return result;
    }
};
