#include <iostream>
#include <vector>
using namespace std;
/*
http://pochenfullwave.ddns.net/?p=352
https://www.geeksforgeeks.org/lexicographically-previous-permutation-in-c/
*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
        1. find the point where the tail array starts to decrease
        2. swap the fisrt element in the tail array which is just larger than the previous point of change point
        3. reverse order of tail array
        
        plot a diagram to explain. 
           x(chage point) 
          / \
         /  <idx>
        p     \
               x
        consider corner case: ex: 54321
        */
        int idx = nums.size() - 1;
        while (idx - 1 > -1 && nums[idx-1] >= nums[idx]) idx--;
        int pivot = idx - 1;
        if (pivot > -1) {
            //we can use binary search to get the idx!
            while (idx + 1 < nums.size() && nums[idx+1] > nums[pivot]) idx++;
            swap(nums[pivot], nums[idx]);
        }
        reverse(nums.begin() + pivot + 1, nums.end());
    }
    void previousPermutation(vector<int>& nums) {
        /*
        previous permutation : use the same approach 
        */
        int idx = nums.size() - 1;
        while (idx - 1 > -1 && nums[idx-1] <= nums[idx]) idx--;
        int pivot = idx - 1;
        if (pivot > -1) {
            while (idx + 1 < nums.size() && nums[idx+1] < nums[pivot]) idx++;
            swap(nums[pivot], nums[idx]);
        }
        reverse(nums.begin() + pivot + 1, nums.end());
    }

};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums{4, 3, 2, 1};
    s.nextPermutation(nums);
    for (auto cell : nums) {
        cout << cell << " ";
    }
    cout << endl;
    vector<int> nums1{4, 3, 2, 1};
    s.previousPermutation(nums1);
    for (auto cell : nums1) {
        cout << cell << " ";
    }
    cout << endl;

}

