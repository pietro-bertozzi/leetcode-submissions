class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";
        const auto& v = it->second;
        int l = 0, r = v.size() - 1;
        string result = "";
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m].first <= timestamp) {
                result = v[m].second;
                l = m + 1;
            } else r = m - 1;
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
