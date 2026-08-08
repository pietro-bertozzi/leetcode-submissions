class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> wants(2, 0);
        for (int s : students) wants[s]++;
        int remaining = sandwiches.size();
        for (int s : sandwiches) if (!wants[s]-- || !remaining--) break;
        return remaining;

    }
};
