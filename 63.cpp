/*
Time: O(mn)
Space: O(mn)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> dp(m + 1, vector<long> (n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (obstacleGrid[i-1][j-1] == 0) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
