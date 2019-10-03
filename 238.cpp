class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        [1,2,3,4]
           o[1]
           cmpt = 4x3
        l[]: the cumulative product of nums from the leftmost to the rightmost
        r[]: ... rightmost to leftmost
        o[i] = l[i-1] * r[i+1]

        notice: edge case for res[0]        
        */
        int n = nums.size();
        vector<int> res(n, nums[0]);
        for (int i = 1; i < n; ++i) {
            res[i] = res[i-1] * nums[i];
        }
        int cmpt = 1;
        for (int i = n - 1; i > -1; --i) {
            if (i > 0) res[i] = res[i-1] * cmpt;
            else res[i] = cmpt;
            cmpt *= nums[i];
        }
        return res;
    }
};
