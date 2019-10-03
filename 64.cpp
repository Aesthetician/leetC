//Time complexity: O(mn) 
//Space: O(n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> s(n, 0);
        
        s[0] = grid[0][0];
        
        for(int i = 1; i < n; i++) s[i] = s[i-1] + grid[0][i];
        
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0) s[j] = s[j] + grid[i][j];
                else s[j] = min(s[j-1], s[j]) + grid[i][j];
            }
        }
        
        return s[n-1];
    }
};


//Time complexity: O(mn)
//Space: O(mn)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> v(m,vector<int>(n,0));
        
        v[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) v[i][0] = v[i-1][0] + grid[i][0];
        for(int j = 1; j < n; j++) v[0][j] = v[0][j-1] + grid[0][j];
        
        for(int i =1; i < m; i++){
            for(int j = 1; j < n; j++){
                v[i][j] = min(v[i-1][j], v[i][j-1]) + grid[i][j];
            }
        }
        return v[m-1][n-1];
    }
};


