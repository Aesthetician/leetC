class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        cumulative sum array -> presum_min, crt_presum
        */
        int presum_min = 0, crt_presum = 0;
        int max_val = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            crt_presum += nums[i];
            max_val = max(max_val, crt_presum - presum_min);
            presum_min = min(presum_min, crt_presum);
        }
        return max_val;
    }
};
