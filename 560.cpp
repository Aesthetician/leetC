class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        s[i,j] = s[j] - s[i] = k
        s[i] = s[j] - k
        look for i by a dictionay 
        T: O(N); S: O(N)
        corner case : k = 0 ? 
        -> you should check the total count before updating the dict.
        */
        unordered_map<int, int> dict;
        dict[0] = 1;
        int n = nums.size(), sum = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (dict.count(sum - k) > 0) ans += dict[sum - k];
            dict[sum]++;
        }
        return ans;
    }
};
