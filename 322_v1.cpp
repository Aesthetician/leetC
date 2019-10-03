/*
* coins = [2, 3, 5], amount = 6 = 3 + 3 (greedy doesn't work)
f(amount) = min{f(amount-c1)+1, f(amount-c2)+1, f(amount-c3)+1}
dp[7] = 0, M, 1, 1, 2, 1, 2
        ^              ^
       
dp[7] = 0, M, M, M, M, M, M        
*/

#define MAX_INT 0x7FFFFFFF
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty() || amount<0) return -1;          
        vector<int> dp(amount+1, 0);
        for(int i=1; i<=amount; ++i) {
            dp[i] = MAX_INT;
            for(int j=0; j<coins.size(); ++j) {
                if(i>=coins[j] && dp[i-coins[j]]!=MAX_INT) {
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        return (dp[amount]==MAX_INT) ? -1 : dp[amount];
    }
};

