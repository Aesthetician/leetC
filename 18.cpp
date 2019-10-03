//18. 4Sum
//pruning version 1
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*
        sort the nums and apply two sum approach 
        ex : [1, 0, -1, 0, -2, 2]
        fix1  |
        fix2     |
        arr          <         >
        1. form the main body
        2. deal with the duplicate element
        3. do pruning 
        */
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size() - 3; ++i) {
            //pruning 
            if (nums[i] > 0 && nums[i] > target) break;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                //prunning
                if (nums[j] > 0 && nums[i] + nums[j] > target) break;
                //two approach
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int crt = nums[i] + nums[j] + nums[left] + nums[right];
                    if (crt == target) {
                        res.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        while (left + 1 < right && nums[left+1] == nums[left]) left++;
                        while (right - 1 > left && nums[right-1] == nums[right]) right--;
                        left++;
                        right--;
                    } else if (crt > target) {
                        right--;
                    } else {
                        left++;
                    }
                }
                while (j + 1 < nums.size() && nums[j+1] == nums[j]) j++;
            }
            while (i + 1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};

//final pruning version
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*
        sort the nums and apply two sum approach 
        ex : [1, 0, -1, 0, -2, 2]
        fix1  |
        fix2     |
        arr          <         >
        1. form the main body
        2. deal with the duplicate element
        3. do pruning 
        */
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size() - 3; ++i) {
            /*pruning 
            1. current upper bound
            2. current low bound 
            */
            if (nums[i] + nums[nums.size()-3] + nums[nums.size()-2] + nums[nums.size()-1] < target) continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                //prunning
                if (nums[i] + nums[j] + nums[nums.size()-2] + nums[nums.size()-1] < target) continue;
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                //two sum approach
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int crt = nums[i] + nums[j] + nums[left] + nums[right];
                    if (crt == target) {
                        res.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        while (left + 1 < right && nums[left+1] == nums[left]) left++;
                        while (right - 1 > left && nums[right-1] == nums[right]) right--;
                        left++;
                        right--;
                    } else if (crt > target) {
                        right--;
                    } else {
                        left++;
                    }
                }
                while (j + 1 < nums.size() && nums[j+1] == nums[j]) j++;
            }
            while (i + 1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};
