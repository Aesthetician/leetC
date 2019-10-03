class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
        [1,2,1,3,5,6,4]
        n[i-1] < n[i] > n[i+1] ->find
        n[i-1] < n[i] < n[i+1] ->right
        n[i-1] > n[i] > n[i+1] ->left
        n[i-1] > n[i] < n[i+1] ->left or right
        we can simplify the case as seeking the larger one. 
        only compare n[i], n[i+1]
        */
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid+1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
