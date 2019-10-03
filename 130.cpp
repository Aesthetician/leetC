class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> done(m, vector<int> (n, 0));
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O' && done[i][j] == 0) {
                    vector<vector<int>> visit(m, vector<int> (n, 0));
                    if(dfs(i, j, board, visit, done)) flip(i, j, board, visit);
                }
            }
        }
    }
    
    void flip(int i, int j, vector<vector<char>>& board, vector<vector<int>> &visit) {
        for (int y = i; y < board.size(); y++){
            for (int x = 0; x < board[0].size(); x++) {
                //cout << "xy" << x << ";" << y << endl;
                if(visit[y][x] == 1) board[y][x] = 'X';
            }
        }
    }
    
    bool dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &visit, vector<vector<int>> &done) {
        visit[i][j] = 1;
        done[i][j] = 1;
        //cout << "ij" << i << ";" << j << endl;
        bool right = false, down = false, left = false, up = false;
        
        if (i + 1 < board.size()) {
            if (board[i + 1][j] == 'X') down = true;
            else if(visit[i + 1][j] == 0) down = dfs(i + 1, j, board, visit, done);
            else down = true;
        }
        if (j + 1 < board[0].size()) {
            if (board[i][j + 1] == 'X') right = true;
            else if(visit[i][j + 1] == 0) right = dfs(i, j + 1, board, visit, done);
            else right = true;
        }
        if (i - 1 > -1) {
            if (board[i - 1][j] == 'X') up = true;
            else if(visit[i - 1][j] == 0) up = dfs(i - 1, j , board, visit, done);
            else up = true;
        }
        if (j - 1 > -1) {
            if (board[i][j - 1] == 'X') left = true;
            else if(visit[i][j - 1] == 0) left = dfs(i, j - 1, board, visit, done);
            else left = true;
        }
        //cout << "res:" << (right && down && left && up) << endl;
        return right && down && left && up;
        
    }
};
