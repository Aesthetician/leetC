class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;
        int n = nums.size();
        vector<int> memo(n, -1);
        return dfs(0, nums, memo);
    }
    bool dfs(int start, vector<int>& nums, vector<int>& memo) {
        if (memo[start] > -1) return memo[start];
        if (start == nums.size() - 1) return true;
        if (start >= nums.size() || start < nums.size() && nums[start] == 0) return false;
        for (int i = 1; i <= nums[start]; ++i) {
            if (dfs(start + i, nums, memo)) {
                memo[start+i] = 1;
                return true;
            }
        }
        memo[start] = 0;
        return false;
    }
};
