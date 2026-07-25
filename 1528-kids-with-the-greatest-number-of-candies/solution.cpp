class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int best = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        vector<bool> result (n);
        for (int i = 0; i < n; ++i) if (candies[i] >= best - extraCandies) result[i] = true;
        return result; 
    }
};
