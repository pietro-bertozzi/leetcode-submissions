class Solution {
private:
    long getBucketId(long n, long w) {
        return n >= 0 ? n / w : (n + 1) / w - 1;
    }

public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<long, long> bk;
        long w = (long)valueDiff + 1;
        for (int i = 0; i < nums.size(); ++i) {
            long id = getBucketId(nums[i], w);
            if (bk.contains(id)) return true;
            if (bk.contains(id - 1) && abs(nums[i] - bk[id - 1]) <= valueDiff) return true;
            if (bk.contains(id + 1) && abs(nums[i] - bk[id + 1]) <= valueDiff) return true;
            bk[id] = nums[i];
            if (i >= indexDiff) bk.erase(getBucketId(nums[i - indexDiff], w));
        }
        return false;
    }
};
