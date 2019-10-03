class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        /*
        1. max sum of subarray from left to right
        2. max sum of subarray from right to left
        3. scan one by one on the presum array. 
        T: O(N)
        S: O(N)
        */
        int n = nums.size();
        vector<int> presum(n, nums[0]);
        for (int i = 1; i < n; ++i) 
            presum[i] = presum[i-1] + nums[i];
        vector<int> maxL(n, presum[k-1]);
        vector<int> idxL(n, k-1);
        for (int i = k; i < n; ++i) {
            if (presum[i] - presum[i-k] > maxL[i-1]) {
                maxL[i] = presum[i] - presum[i-k];
                idxL[i] = i;
            } else {
                maxL[i] = maxL[i-1];
                idxL[i] = idxL[i-1];
            }
        }
        vector<int> maxR(n, presum[n-1] - presum[n-1-k]);
        vector<int> idxR(n, n - 1);
        for (int i = n - 2; i > k-1; --i) {
            if (presum[i] - presum[i-k] > maxR[i+1]) {
                maxR[i] = presum[i] - presum[i-k];
                idxR[i] = i;
            } else {
                maxR[i] = maxR[i+1];
                idxR[i] = idxR[i+1];
            }
        }
        int max_val = 0;
        vector<int> ans(3, 0);
        for (int i = 2 * k - 1; i < n - k; ++i) {
            if (presum[i] - presum[i-k] + maxL[i-k] + maxR[i+k] > max_val) {
                max_val = presum[i] - presum[i-k] + maxL[i-k] + maxR[i+k];
                ans = {idxL[i-k] - k + 1, i - k + 1, idxR[i+k] - k + 1};
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        /*
        use slidding window to have k-sum
        */
        int n = nums.size();
        vector<int> ksum(n, nums[0]);
        for (int i = 1; i < n; ++i) {
            if (i < k) ksum[i] += nums[i-1];
            else {
               ksum[i] = ksum[i-1] - nums[i-k] + nums[i]; 
            }
        }
        int max_val = ksum[k-1];
        vector<int> idxL(n, k - 1);
        for (int i = k; i < n; ++i) {
            if (max_val < ksum[i]) {
                idxL[i] = i;
                max_val = ksum[i];
            } else {
                idxL[i] = idxL[i-1];
            }
        }
        max_val = ksum[n-1];
        vector<int> idxR(n, n - 1);
        for (int i = n - 2; i > k - 2; --i) {
            if (max_val < ksum[i]) {
                idxR[i] = i;
                max_val = ksum[i];
            } else {
                idxR[i] = idxR[i+1];
            }
        }
        vector<int> ans(3, 0);
        max_val = 0;
        for (int i = 2 * k - 1; i < n - k; ++i) {
            int left = idxL[i-k];
            int right = idxR[i+k];
            if (ksum[left] + ksum[i] + ksum[right] > max_val) {
                max_val = ksum[left] + ksum[i] + ksum[right];
                ans = {left - k + 1, i - k + 1, right - k + 1};
            }
        }
        return ans;
    }
};


