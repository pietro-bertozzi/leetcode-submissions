class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int a: asteroids) {
            if (a > 0) result.push_back(a);
            else {
                while (!result.empty() && result.back() > 0 && abs(a) > result.back()) result.pop_back();
                if (!result.empty() && abs(a) == result.back()) result.pop_back();
                else if (result.empty() || result.back() < 0) result.push_back(a);
            }
        }
        return result;
    }
};
