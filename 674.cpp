class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        /*
        Input: [1,3,5,4,7]
        st            |
        i             |
        */
        if (nums.empty()) return 0;
        int st = 0, max_val = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) max_val = max(max_val, i - st + 1);
            else st = i;
        }
        return max_val;
    }
};
