class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        /*
        thinking process: 
        starting thought : prefix sum
        s[i,j] = s[j] - s[i] >= k
        => s[i] <= s[j] - k
        for s[j] we will find s[i] such that s[i] <= s[j] - k
        1. naive approach O(N^2):
          xxxxxxx s[j]
        i    *
        2. use priority queue to store presum array 0-(j-1)
        start searching from the smallest one
        Ex: 
        If we have an array prefix sum array like [0,1,2,3,4,10,7,4,5,14,16,....... ], K=11
        The best answer is: length=2 (i=8, j=10).
        3. optimal approach : dequeue
    
    https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C++JavaPython-O(N)-Using-Deque?page=2
        */
        int n = A.size();
        vector<int> presum(n + 1, A[0]);
        for (int i = 1; i <= n; ++i) presum[i] = presum[i-1] + A[i-1];
        deque<int> dque;
        int min_val = n + 1;
        for (int i = 0; i <= n; ++i) {
            while (!dque.empty() && presum[dque.front()] <= presum[i] - K) {
                min_val = min(min_val, i - dque.front());
                dque.pop_front();
            }
            while (!dque.empty() && presum[dque.back()] >= presum[i]) {
                dque.pop_back();
            }
            dque.push_back(i);
        }
        return min_val == n + 1 ? -1 : min_val;
    }
};
