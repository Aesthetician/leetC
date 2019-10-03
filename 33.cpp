/*
33. Search in Rotated Sorted Array
@ 8.10.2019
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        One of the partitions must be a normal sorted array
        For a sorted array, the left element is smaller than the right one.
        
        case1: M > leftmost -> left part is a normal sorted array 
        4567890123
            M
        if target < M and target > lefmost, search left part 
        else search left part 
        
        case2: M < leftmost -> right part is a normal sorted array
        7890123456
            M
        if target > M and target < rightmost, search right part
        else search left part
        
        point1: right should be n-1, because we will use nums[right]
        point2: notice the equal condition.
            1. nums[left] <= nums[mid]
            2. in the sorted array 
                a. nums[left] <= target < nums[mid]
                b. nums[mid] < target <= nums[right]
        
        corner case: 
        1. [3,1] target = 1
        2. [1] target = 1, we have left <= right in the while loop. 
        */
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[left] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int left = 0, right = n - 1;
        //usually make mistakes when choosing right = n 
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[left]) {
                //"=" should be included because "mid" could be equal to "left";  
                if (target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid -1;
            }
        }
        return -1;
    }
};
