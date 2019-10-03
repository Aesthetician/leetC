class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visit(m, vector<int> (n, 0));
        int res = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && visit[i][j] == 0){
                    res += dfs(i, j, grid, visit);
                    //cout << "ij" << i << ";" << j << endl;
                } 
            }
        }
        return res;
    }
    
    int dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visit){
        stack<pair <int, int>> stk;
        pair <int, int> xy;
        stk.push(make_pair(i, j));
        
        while(!stk.empty()){
            xy = stk.top();
            visit[xy.first][xy.second] = 1;
            stk.pop();
            if(xy.first - 1 > -1 && grid[xy.first - 1][xy.second] == '1' 
               && visit[xy.first - 1][xy.second] == 0) 
                stk.push(make_pair(xy.first - 1, xy.second));
            if(xy.second - 1 > -1 && grid[xy.first][xy.second - 1] == '1' 
               && visit[xy.first][xy.second - 1] == 0) 
                stk.push(make_pair(xy.first, xy.second - 1));
            if(xy.first + 1 < grid.size() && grid[xy.first + 1][xy.second] == '1' 
               && visit[xy.first + 1][xy.second] == 0) 
                stk.push(make_pair(xy.first + 1, xy.second));
            if(xy.second + 1 < grid[0].size() && grid[xy.first][xy.second + 1] == '1' 
               && visit[xy.first][xy.second + 1] == 0) 
                stk.push(make_pair(xy.first, xy.second + 1));
        }
        return 1;
    }
};
