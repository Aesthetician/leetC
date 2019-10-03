class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        /*
        the sum of subarray from i+1 to j = difference of running sum at index j and i
        sum[i,j] = s[j] - s[i] = n * k
        (s[j] - s[i]) % k = 0 -> same remainder
        
        corner case: 
        k=0 or nums=[0,0]
        k is negative -> the same as the normal case  
        */
        unordered_map<int, int> dict;
        dict[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (k != 0) {
                if (dict.count(sum % k) > 0) {
                    if (i - dict[sum % k] > 1) return true;
                } else {
                    dict[sum % k] = i;
                }
            }
        }
        if (sum == 0 && nums.size() > 1) return true;
        return false;
    }
};
