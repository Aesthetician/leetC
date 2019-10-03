//128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> hset(nums.begin(), nums.end());
        int max_val = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (hset.count(nums[i]) == 0) continue;
            hset.erase(nums[i]);
            int left = nums[i] - 1;
            int right = nums[i] + 1;
            while (hset.count(left) > 0) hset.erase(left--);
            while (hset.count(right) > 0) hset.erase(right++);
            max_val = max(max_val, right - left - 1); 
        }
        return max_val;
    }
};
