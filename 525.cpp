class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> htable;
        int cnt=0;
        int maxLength=0;
        //for the case of 01, 0011 ... 
        htable.insert({0,-1});
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) cnt+=-1;
            else cnt+=1;
            if(htable.count(cnt)>0){
                maxLength=max(maxLength, i-htable[cnt]);
            }else{
                htable.insert({cnt,i});
            }
        }
        return maxLength;
    }
};
