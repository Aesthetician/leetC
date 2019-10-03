class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        /*
        1. DFS visit the graph 
        2. record number of steps to reach current node 
        3. if the current number of steps to reach a node is greater than in the previous iteration, update the steps variable to reflect most recent number of steps.
        */
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> reach(m, vector<int> (n, 0));
        int max_val = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = dfs(i, j, matrix, reach, 1);
                max_val = max(max_val, len);
            }
        }
        return max_val;
    }
    
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& reach, int steps) {
        if (steps <= reach[i][j]) return 0;
        reach[i][j] = steps;
        int left = 0;
        int right = 0;
        int up = 0;
        int down = 0;
        if (i + 1 < matrix.size() && matrix[i][j] < matrix[i+1][j]) 
            down = dfs(i + 1, j, matrix, reach, steps + 1);
        if (i - 1 > -1 && matrix[i][j] < matrix[i-1][j]) 
            up = dfs(i - 1, j, matrix, reach, steps + 1);
        if (j + 1 < matrix[0].size() && matrix[i][j] < matrix[i][j+1]) 
            right = dfs(i, j + 1, matrix, reach, steps + 1);
        if (j - 1 > -1 && matrix[i][j] < matrix[i][j-1]) 
            left = dfs(i, j - 1, matrix, reach, steps + 1);
        return max(max(left, right), max(up, down)) + 1;
    }
};
