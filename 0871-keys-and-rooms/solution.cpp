class Solution {
private:
    void dfs(vector<vector<int>>& rooms, unordered_set<int>& open, int key) {
        open.insert(key);
        for (int k : rooms[key]) {
            if (open.find(k) == open.end()) {
                dfs(rooms, open, k);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> open;
        dfs(rooms, open, 0);
        return open.size() == rooms.size();
    }
};
