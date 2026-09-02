class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int s1 = 0, s2 = 0, c1 = 0, c2 = 0;
        for (int num : nums) {
            if (num == s1) c1++;
            else if (num == s2) c2++;
            else if (!c1) {
                s1 = num;
                c1 = 1;
            } else if (!c2) {
                s2 = num;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }
        c1 = 0, c2 = 0;
        for (int num : nums) {
            if (num == s1) c1++;
            else if (num == s2) c2++;
        }
        vector<int> result;
        int n = nums.size();
        if (c1 > n / 3) result.push_back(s1);
        if (c2 > n / 3) result.push_back(s2);
        return result;
    }
};
