//15. 3Sum
//http://blog.gainlo.co/index.php/2016/07/19/3sum/?utm_source=glassdoor&utm_medium=811/16&utm_campaign=glassdoor
//https://fizzbuzzed.com/top-interview-questions-1/
/*
#15
-how to deal with duplicate case.
-corner case: 
  [0,0,0,0,0,0,0]
  [-1,-1,-1,0,2,2]

        the array is with duplicate elements.
        ex: 1 1 2 3 3 4
        fix |
        arr   <       > -- apply two sum approach
*/

//sol1 : sort the array 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    /*deal with the duplicate elements 
                    ex 1 2 3 3 4 4
                                 |
                             |
                    */
                    while (nums[left+1] == nums[left]) left++;
                    while (nums[right-1] == nums[right]) right--;
                    left++;
                    right--;
                } else if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return res;
    }
};

//without sorting: sol1 - grouping 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        how to avoid duplicate?
        1. grouping the same element 
        */
        vector<vector<int>> res;
        //preprocessing
        vector<int> gNums = grouping(nums);
        
        for (int i = 0; i < gNums.size(); ++i) {
            int target = 0 - gNums[i];
            //two sum approach with hash
            unordered_set<int> hset;
            for (int j = i + 1; j < gNums.size(); ++j) {
                if (hset.count(target - gNums[j]) > 0) {
                    res.push_back(vector<int> {gNums[i], target - gNums[j], gNums[j]});
                    while (j < gNums.size() && gNums[j+1] == gNums[j]) j++;
                } else {
                    hset.insert(gNums[j]);
                }
            }
            while (i < gNums.size() && gNums[i+1] == gNums[i]) i++;
        }
        return res;
    }
    vector<int> grouping(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); ++i) {
            dict[nums[i]]++;
        }
        vector<int> gnums;
        for (int i = 0; i < nums.size(); ++i) {
            if (dict[nums[i]] == 0) continue;
            while (dict[nums[i]] > 0) {
                gnums.push_back(nums[i]);
                dict[nums[i]]--;
            }
        }
        return gnums;
    }
};


//without sorting: sol2 - two set to record result  
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        use two set to record the duplicate element. 
        */
        vector<vector<int>> res;
        unordered_set<int> set1;
        for (int i = 0; i < nums.size(); ++i) {
            if (set1.count(nums[i]) > 0) continue;
            unordered_set<int> hset;
            unordered_set<int> set2;
            int target = 0 - nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                if (!set1.count(nums[j]) && !set2.count(nums[j])) {
                    if (hset.count(target - nums[j]) > 0) {
                        res.push_back({nums[i], nums[j], target - nums[j]});
                        set2.insert(nums[j]);
                    } else {
                        hset.insert(nums[j]);
                    }
                }
            }
            set1.insert(nums[i]);
        }
        return res;
    }
};


//without sorting: sol3 - translate the result as a string.  
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        how to avoid the duplicate result
        1. translate result as a string and use a hash to check it
        */
        unordered_set<string> triplets;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            unordered_set<int> hset;
            int target = 0 - nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                if (hset.count(target - nums[j]) > 0) {
                    string ans = toString(nums[i], nums[j], target - nums[j]);
                    if (triplets.count(ans) == 0) {
                        triplets.insert(ans);
                        res.push_back({nums[i], nums[j], target - nums[j]});
                    }
                } else {
                    hset.insert(nums[j]);
                }
            }
        }
        return res;
    }
    string toString(int a, int b, int c) {
        int x1 = max(a, max(b, c));
        int x2;
        int x3 = min(a, min(b, c));
        x2 = a + b + c - x1 - x3;
        return to_string(x1) + '#' + to_string(x2) + '#' + to_string(x3);
    }
};
