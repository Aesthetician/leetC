class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
        j:current amount
        i:coins[0~i]
        dp[i][j]
        coins[i]: 1, 2, 5
        dp[0][j]
        dp[0][0] d[0][1] dp[0][2] dp[0][3] ----- d[0][j]
        1           1       1       1               1
        dp[1][0] d[1][1] dp[1][2] dp[1][3] ----- d[1][j]
        1           1       1       1+1          dp[0][j] + dp[1][j-coins[i]]
                                    dp[0][3] + dp[1][1]
        dp[i][0] d[i][1] dp[i][2] dp[i][3] ----- dp[i][j]
        1                                      dp[i-1][j] + dp[i][j-coins[i]]
        dp[i][j] = 
           1. dp[i-1][j] if j-coins[i] < 0
           2. dp[i-1][j] + dp[i][j-coins[i]], if j - coins[i] >= 0
              coins[i] is not used + coins[i] is used
        
        corner case:
        when to return 0?
        coins[i]: 2, 5
        dp[0][0] d[0][1] dp[0][2] dp[0][3] ----- d[0][j]
        1           0       1       0            d[0][j-coins[i]]
        */
        int n = coins.size();
        if (amount == 0) return 1;
        if (amount != 0 && n == 0) return 0;
        vector<vector<int>> dp(n, vector<int> (amount + 1, 1));
        dp[0][0] = 1;
        for (int i = 1; i < amount + 1; ++i) {
            if (i - coins[0] < 0) dp[0][i] = 0;
            else dp[0][i] = dp[0][i-coins[0]];
            //cout << i << ";" << dp[0][i] << endl;
            
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < amount + 1; ++j) {
                if (j - coins[i] < 0) dp[i][j] = dp[i-1][j];
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
                    //cout << "dpi,j-coin= " << dp[i][j-coins[i]] << endl;
                    }
                //cout << i << ";" << j << ";" << dp[i][j] << endl;
            }
        }
        return dp[n-1][amount];
    }
};
