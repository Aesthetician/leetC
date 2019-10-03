

//123. Best Time to Buy and Sell Stock III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        [--------]
            j: 0 ~ n-1 
        left  right
        0~j   j+1~n-1 
        */
        int n = prices.size();
        if (n == 0) return 0;
        int crtmin = prices[0];
        vector<int> left(n , 0);
        for (int i = 1; i < n; ++i) {
            crtmin = min(crtmin, prices[i]);
            left[i] = max(left[i-1], prices[i] - crtmin);
        }
        vector<int> right(n , 0);
        int crtmax = prices[n-1];
        for (int i = n - 2; i > -1; --i) {
            crtmax = max(crtmax, prices[i]);
            right[i] = max(right[i+1], crtmax - prices[i]);
        }
        int max_val = 0;
        for (int i = 1; i < n - 1; ++i) {
            max_val = max(max_val, left[i] + right[i+1]);
        }
        max_val = max(max_val, max(left[n-1], right[0]));
        return max_val;
    }
};


//121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
         [7,1,5,3,6,4]
        */
        if (prices.empty()) return 0;
        int minp = prices[0], max_val = 0;
        for (int i = 1; i < prices.size(); ++i) {
            max_val = max(max_val, prices[i] - minp);
            minp = min(minp, prices[i]);
        }
        return max_val;
    }
};


//122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) sum += prices[i] - prices[i-1];
        }
        return sum;
    }
};
