#include <iostream>
#include <vector>
#include <algorithm>    
using namespace std;


int kth_with_k_and_k_1(vector<int> &A, vector<int> &B, int k) {
    /*
    for kth element, we consider kth and k+1th elements in A and B arrays.
    0. We use 0-based indexing. 
    1. Because we don't know the relation between A[j] and B[i], we have to consider kth and k+1th elements in A and B. 
    2. If we consider kth and k-1th elements in A and B, we might lose the correct answer. 
        Ex: A = [1, 2], B = [3, 4], and k = 2
        We will consider B[0] and A[0], and find the maximal one. However, the answer is A[1], which is not considered! 
    3. If we reach the target, kth element in the two arrays. 
        A[j-1] <= B[i] and A[j] >= B[i-1]
    4. We search the small array and limit the search range in the minimal of k and the size of the small array.  
        Ex: k = 3
            B = [0,1,2,3,4,5,6,7,8]
        left     |
        right_0          |
        right        |
        Actually, it is better to start with "right" instead of "right_0".
        right = min(B.size(), k-1)
    Example:
    k = 4
    A = [1,2,3,4]
    j0     |     
    j1       |
    j2         |
    B = [5,6,7,8]
    i0       |    
    i1     |
    i2   |
    kth = min(A[3], B[0]) = 4
    
    ref: 
    https://algorithmsandme.com/find-kth-smallest-element-in-two-sorted-arrays/
    http://nriverwang.blogspot.com/2013/04/k-th-smallest-element-of-two-sorted.html?m=1
    */
    if (A.size() < B.size()) return kth_with_k_and_k_1(B, A, k);
    int n = B.size();
    int left = 0, right = min(k - 1, n);
    while (left < right) {
        int i = (left + right) >> 1;
        int j = k - i - 1;
        //i is too small
        if (j > 0 && A[j-1] > B[i]) {
            left = i + 1;
        } else {
            right = i;
        }
    }
    cout << "left:" << left << endl;
    return min(A[k-left-1], B[left]);
}


int main() {
    int k = 2;
    vector<int> nums1 = {3,7,8,9};
    vector<int> nums2 = {2,11,17,21,23};
    // 2 3 7 8 9 11 17 21 23
    //   *    
    cout << kth_with_k_and_k_1(nums1, nums2, k) << endl;

    vector<int> nums3 = {1,3};
    vector<int> nums4 = {4,5};
    cout << kth_with_k_and_k_1(nums3, nums4, k) << endl;
    
    vector<int> nums5 = {1,3};
    vector<int> nums6 = {2};
    cout << kth_with_k_and_k_1(nums5, nums6, k) << endl;

    vector<int> nums7 = {1,2};
    vector<int> nums8 = {3,4};
    cout << kth_with_k_and_k_1(nums7, nums8, k) << endl;
}

