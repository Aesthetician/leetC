class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        /*
        use the index as an position operaor to make the number at the position negative. 
        1223
        -1
         -2
           +2!->duplicate for index "2" 
        */
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            nums[idx] *= -1;
            if (nums[idx] > 0) res.push_back(idx + 1); 
        }
        return res;
    }
};
