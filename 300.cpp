class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        [10,9,2,5,3,7,101,18]
        10->101
        9->101
        2->5
        2->3
        2->7
        2->101
        2->18
        5->7
        5->101
        5->18
        3->7
        3->101
        3->18
        7->101
        7->18
        101->x
        18->x
        consider the sequence ending with "7", we have the following choices 
        2->7
        3->7
        5->7
        which is the best? the longest increasing subsequence to "7".
        2->3->7
        2->5->7
        def : lis[i]: the len of LIC ending with num[i] with idx i. 
        lis[i] = max(lis[i-1] ~ lis[0], ie: lis[i-j]) + 1 if nums[i-j] < nums[i], j = 1 ~ i
        */
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> lis(n, 0);
        lis[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int max_val = 0;
            for (int j = 1; j <= i; ++j) {
                if (nums[i-j] < nums[i]) max_val = max(max_val, lis[i-j]);
            }
            lis[i] = max_val + 1;
            ans = max(ans, lis[i]);
        }
        return ans;
    }
};
