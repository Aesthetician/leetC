
/*
https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation?page=2

Why it can not start from i = 1?

Because dp[i] = dp[i] || dp[i-num] uses smaller index value dp[i-num].
When the current iteration begins, the values in dp[] are the result of previous iteration.
Current iteration's result should only depend on the values of previous iteration.
If you iterate from i = 0, then dp[i-num] will be overwritten before you use it, which is wrong.
You can avoid this problem by iterating from i=sum




*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (auto num : nums) total += num;
        if (total & 1) return false;
        int sum = total / 2;
        int n = nums.size();
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = sum; j > 0; --j) {
                if (j >= nums[i]) dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (auto num : nums) total += num;
        if (total & 1) return false;
        int sum = total / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool> (sum + 1, false));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= sum; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j-nums[i-1] >= 0) dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];                
            }
        }
        return dp[n][sum];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (auto num : nums) total += num;
        if (total & 1) return false;
        sort(nums.begin(), nums.end());
        return helper(nums.size() - 1, 0, total / 2, nums);
    }
    bool helper(int i, int sum, int target, vector<int> &nums) {
        if (i < 0) return false;
        if (i < nums.size() && sum == target) return true;
        if (i < nums.size() && nums[i] > target) return false;
        if (i < nums.size() && sum > target) return false;
        return helper(i - 1, sum + nums[i], target, nums) ||
            helper(i - 1, sum, target, nums);
    }
};


