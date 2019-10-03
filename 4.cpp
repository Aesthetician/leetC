class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        j: idx of nums1
        i: idx of nums2
        we consider k+2 elements by choosing i and j = k-i (i+1 and k-i+1 elements) 
        and choose i,j such that  
        nums1[j-1] < nums2[i]
            given : nums1[j-1] < nums1[j]
                    nums2[i-1] < nums2[i]
        nums2[i-1] or nums1[j-1] < nums2[i] or nums1[j]
        so we have (k-1, k, k+1, k+2)-th elements in hand.
        1. for odd number of elements, we consider (k-1 and k)-th elements.
            median = max(k-1 th, k th)
        2. for even number of elements, 
            we consider (k-1 and k)-th elements for the maximun of lower subarray, and
            we consider (k+1 and k+2)-th elements for the minimun of upper subarray. 
            median = (max(k-1 th, k th)  + min(k+1 th, k+2 th)) / 2 
        
        For the corner case:
        We use i = (left0 + right0) >> 1
        a. left = i + 1 
        b. right = i
        , so left0 <= i <= right0, where left0 = 0 and rigth0 = min(k, nums2.size())
        
        1. i search beyond the rightmost one.
        nums1: [x x x x x x]
                    j
        nums2: [x x x x] INT_MAX
                         i
        2. i search below the leftmost one.
        nums1: [x x x x x x]
        nums2: INT_MIN [x x x x]
                        i       
        */
        
        int m = nums1.size(), n = nums2.size();
        if (m < n) return findMedianSortedArrays(nums2, nums1);
        int k = (m + n + 1) >> 1;
        int left = 0, right = min(k, n);
        while (left < right) {
            int i = (left + right) >> 1;
            int j = k - i;
            if (j > 0 &&  nums2[i] < nums1[j-1]) {
                left = i + 1;
            } else {
                right = i;
            }
        }
        //cout << "left:" << left << endl;
        //for odd number of array, we consider the following.
        //k-left-1 <= (m+n+1)/2 - 0 - 1 = (2m+1)/2 - 1 <= m - 1 < m, so we only consider k-left > 0
        int lower_in_nums1 = k - left > 0 ? nums1[k-left-1] : INT_MIN;
        int lower_in_nums2 = left == 0 ? INT_MIN : nums2[left-1];
        //cout << lower_in_nums1 << ";" << lower_in_nums2 << endl;
        int max_of_lower_subarray = max(lower_in_nums1, lower_in_nums2);
        if ((m+n) & 1) {
            return max_of_lower_subarray;
        }
        //for even number of array, we also consider the following.
        //k-left = (m+n+1)/2 - left >= (m+n+1)/2 - n >= (2n+1)/2 - n > 0, so we only consider k-left < m 
        int upper_in_nums1 = k - left < m ? nums1[k-left] : INT_MAX;
        int upper_in_nums2 = left == n ? INT_MAX : nums2[left];
        //cout << "upper: " << upper_in_nums1 << ";" << upper_in_nums2 << endl;
        int min_of_upper_subarray = min(upper_in_nums1, upper_in_nums2);
        return (max_of_lower_subarray + min_of_upper_subarray) / 2.0;   
    }
};
