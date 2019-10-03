class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        L[i]: the length of LIS at nums[i]
        When num[i] is being considered to be a new eleement of the new LIS sequence,
        L[i] = max of L[j]+1 and L[i] if num[i] > num[j]
        */
        vector<int> LIS(nums.size(),1);
        int lenghLIS=0;
        if(nums.empty()) return 0;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j])
                    LIS[i] = maxof(LIS[j]+1, LIS[i]);
            }
        }
        return maxof(LIS);
    }
    
    int maxof(int a, int b){
        if(a>b) return a;
        return b;
    }
    int maxof(vector<int> v){
        int max=v[0];
        for(int i=0;i<v.size();i++){
            if(max<v[i]) max=v[i];
        }
        return max;
    }
};
