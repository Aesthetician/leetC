/*
628. Maximum Product of Three Numbers
https://leetcode.com/problems/maximum-product-of-three-numbers/discuss/128740/General-solution-for-any-K
*/

    



/*
idea1:
1. sort the array 
2. return max of product of 3 leftmost elements or 3 rightmost elements.

pseudocdoe
sort(A)
return max(A[0]*A[1]*A[2], A[n-3]*A[n-2]*A[n-1])

idea2:
1. max1, max2, max3
2. scan the array and find max1 -- max3

pseudocode
max1 = max2 = max3 = A[0]
for i = 1 .. n - 1:
    if A[i] > max1:
        max3 = max2
        max2 = max1
        max1 = A[1]
    else if A[i] > max2:
        max3 = max2
        max2 = A[i]
    else if A[i] > max3:
        max3 = A[i]
return max1 * max2 * max3
*/
