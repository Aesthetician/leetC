class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        /*
        convert a map into a graph and think how to apply DFS to the graph instead of the map!
        0 0 1 0 0
        0 0 0 0 0
        0 0 0 1 0
        1 1 0 1 1
        0 0 0 0 0
        explain the map as the following graph
              0-0
              | |
           0--0 |
                0
        */
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        return dfs(start[0], start[1], destination, visited, 0, dir, maze);
    }
    bool dfs(int i, int j, vector<int>& destination, vector<vector<bool>>& visited, int d, vector<vector<int>>& dir, vector<vector<int>>& maze) {
        if (i == destination[0] && j == destination[1]) return true;
        visited[i][j] = true;
        //change the direction
        for (int k = 0; k < 4; ++k) {
            //keeping the same direction
            int ni = i;
            int nj = j;
            while(isValid(ni + dir[d][0], nj + dir[d][1], maze.size(), maze[0].size()) 
                  && !maze[ni+dir[d][0]][nj+dir[d][1]]) {
                ni += dir[d][0];
                nj += dir[d][1];
            }
            if (isValid(ni, nj, maze.size(), maze[0].size()) && !maze[ni][nj] && !visited[ni][nj]
                && dfs(ni, nj, destination, visited, d, dir, maze)) 
                return true;
            d = (d + 1) % 4;
        }
        return false;
    }
    bool isValid(int i, int j, int m, int n) {
        return i < m && i > -1 && j < n && j > -1;
    }
};
