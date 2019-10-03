//1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        You may assume that each input would have exactly one solution, 
        and you may not use the same element twice.
        Q: can the number be duplicated?
        No, because it has exactly one solution!
        target - num1 = num2
        1. by the current number, check if there is any previous number adding up to the target
        2. if not, put the current number into the dictionary.
        */
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); ++i) {
            if (dict.count(target-nums[i]) > 0) return vector<int> {dict[target - nums[i]], i};
            dict[nums[i]] = i;
        }
        return vector<int> ();
    }
};


//167. Two Sum II - Input array is sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                res.push_back(left + 1);
                res.push_back(right + 1);
                return res;
            } else if (numbers[left] + numbers[right] > target) {
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
};

//sorted array and more than one solution. 
class Solution {
public:
	vector<vector<int>> twoSumSortedArrayMoreThanOneAns(vector<int>& numbers, int target) {
		vector<vector<int>> res;
		int left = 0, right = numbers.size() - 1;
		while (left < right) {
			if (numbers[left] + numbers[right] == target) {
				res.push_back(vector<int> {left, right});
				left++;
				right--;
			} else if (numbers[left] + numbers[right] > target) {
				right--;
			} else {
				left++;
			}
		}
		return res;
	}
};


//170. Two Sum III - Data structure design
//iterate by hash
class TwoSum {
    unordered_map<int, int> dict;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        dict[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            if (value - it->first == it->first) {
                if (it->second > 1) return true;
                else continue;
            }
            if (dict.count(value - it->first) > 0) return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */

//iterate by a vector
/*
There's nothing surprising that iterating a count map is slower than iterating a list, if you take a look at the source code of Java hashmap, or simply take a look at Java doc:
https://leetcode.com/problems/two-sum-iii-data-structure-design/discuss/52015/Beats-100-Java-Code
*/
class TwoSum {
    unordered_map<int, int> dict;
    vector<int> arr;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        dict[number]++;
        arr.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (int i = 0; i < arr.size(); ++i) {
            if (value - arr[i] == arr[i]) {
                if (dict[arr[i]] > 1) return true;
                else continue;
            }
            if (dict.count(value-arr[i]) > 0) return true;
        }
        return false;
    }
};


