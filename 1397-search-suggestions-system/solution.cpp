class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> results;
        sort(products.begin(), products.end());
        int l = 0, r = products.size() - 1;
        for (int i = 0; i < searchWord.size(); ++i) {
            char c = searchWord[i];
            while (l <= r && (i >= products[l].size() || products[l][i] < c)) l++;
            while (l <= r && (i >= products[r].size() || products[r][i] > c)) r--;
            vector<string> suggestions;
            for (int j = l; j <= r && suggestions.size() < 3; ++j) {
                suggestions.push_back(products[j]);
            }
            results.push_back(suggestions);
        }
        return results;
    }
};
