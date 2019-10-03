/*
1004. Max Consecutive Ones III
https://leetcode.com/problems/max-consecutive-ones-iii/discuss/247543/O(n)-Java-Solution-using-sliding-window
*/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, cnt = 0, max_val = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 0) cnt++;
            while (cnt > K) {
                if (A[left] == 0) cnt--;
                left++;
            }
            max_val = max(max_val, i - left + 1);
        }
        return max_val;
    }
};


/*
1st idea (X)
            0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8
Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
          i         |      
Queue: 0 1 4           
1. use a queue to store the idx of 0, and the queue size is K
2. record the max len when queue is full and i reach '0'
3. pop front of the queue and let the i able to move on

pseudocode
for i = 0 .. n:
    if arr[i] == 1, continue 
    if queue.size() < k, queue.push(i)
    else {
        max_val = max(max_val, i - queue.front());
        queue.pop()
        queue.push(i)
    }

failure case:
Ex : [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1] K = 3
    i           |        
queue: 0(x) 1 4 5; max_val = 5 - 0 = 5  
    i                   |   
queue: 0(x) 1(x) 4 5 9; max_val = 9 - 1 = 8  
    i                         |   
queue: 0(x) 1(x) 4(x) 5 9 12; max_val = 12 - 4 = 8  

2nd idea
      0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8
Ex : [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1] K = 3
    L |
    R           |
    K   2     3 
    max = 5 - 0 = 5
    L   |
    R                   |
    K   2     3 3
    max = 9 - 1 = 8
    L     |
    R                         |
    K   2     3 3       3
    max = 12 - 2 = 10
*/          

