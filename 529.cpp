class Solution {
public:
    /*
    1. visit each node by DFS 
    2. use memoization to reduce the time complexity
    T(n) = O(mn); each node is visited only once
    S(n) = O(mn); use 2D matrix to memoize the maximal path of each node. 
    */
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int> (n, 0));
        int max_val = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                max_val = max(max_val, dfs(i, j, matrix, cache));
            }
        }
        return max_val;
    }
    int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &cache) {
        if (cache[i][j] > 0) return cache[i][j];
        for (int k = 0; k < 4; ++k) {
            int y = i + dir[k][0];
            int x = j + dir[k][1];
            if (y > -1 && y < matrix.size() && x > -1 && x < matrix[0].size() && matrix[y][x] > matrix[i][j]) {
                cache[i][j] = max(cache[i][j], dfs(y, x, matrix, cache));
            }
        }
        cache[i][j]++;
        return cache[i][j];
    }
};


