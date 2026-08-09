class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start < 0 || start >= arr.size()) return false;
        if (arr[start] < 0) return false;
        if (arr[start] == 0) return true;
        int step = arr[start];
        arr[start] = -arr[start];
        return canReach(arr, start + step) || canReach(arr, start - step);
    }
};
