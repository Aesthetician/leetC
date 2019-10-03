/*
we consider right flat condition first. 
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /*
        case1
        4566678901123
              M
        case2
        7890112345666
              M
        case3.1
        1111111222211
              M
        case3.2
        1112221111111
              M
           | |  
           left
             right
        -> left+1 and right-1 to reduce the problem as the one without duplicates.   
        
        corner case:
        1. [3,1,1] target = 3
        2. case3.1 and case3.2 
        we should consider 
        if (nums[mid] <= nums[right]) or if (nums[mid] >= nums[left]) to make sure whether target 
        within the flat zone or not. 

        notice the equal condition
            a. nums[left] <= target = nums[mid]
            b. nums[mid] < target <= nums[right]
        */
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left++;
                right--;
            // *** we consider right flat condition first     
            } else if (nums[mid] <= nums[right]) { // right part is a normal sorted array
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else { // left part is a normal sorted array 
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};

/*
we consider left flat condition first. 
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left++;
                right--;
            // *** we consider left flat condition first     
            } else if (nums[mid] >= nums[left]) { // left part is a normal sorted array
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // right part is a normal sorted array 
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            //the following statement is to ignore duplucate elements 
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};
