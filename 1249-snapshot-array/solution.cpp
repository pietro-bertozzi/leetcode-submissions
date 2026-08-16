class SnapshotArray {
private:
    int snap_id = 0;
    vector<vector<pair<int, int>>> history;

public:
    SnapshotArray(int length) {
        history.resize(length);
        for (int i = 0; i < length; ++i) {
            history[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        if (!history[index].empty() && history[index].back().first == snap_id) {
            history[index].back().second = val;
        } else {
            history[index].push_back({snap_id, val});
        }
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        const auto& v = history[index];
        int l = 0, r = v.size() - 1;
        int result = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m].first <= snap_id) {
                result = v[m].second;
                l = m + 1;
            } else r = m - 1;
        }
        return result;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
