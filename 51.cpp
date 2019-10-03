class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag45(2 * n - 1, false);
        vector<bool> diag135(2 * n - 1, false);
        vector<vector<string>> res;
        vector<string> path;
        helper(0, path, res, col, diag45, diag135, n);
        return res;
    }
    void helper(int i, vector<string> path, vector<vector<string>>& res, vector<bool>& col, vector<bool>& diag45, vector<bool>& diag135, int n) {
        if (i == n) {
            res.push_back(path);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (isNotAvailable(i, j, col, diag45, diag135, n)) continue;
            string s(n , '.');
            s[j] = 'Q';
            path.push_back(s);
            update(i, j, col, diag45, diag135, true, n);
            helper(i + 1, path, res, col, diag45, diag135, n);
            update(i, j, col, diag45, diag135, false, n);
            path.pop_back();
        }
    }
    bool isNotAvailable(int i, int j, const vector<bool>& col, const vector<bool>& diag45, const vector<bool>& diag135, int n) {
        return col[j] || diag45[j-i+n-1] || diag135[i+j];
    }
    void update(int i, int j, vector<bool>& col, vector<bool>& diag45, vector<bool>& diag135, bool val, int n) {
        col[j] = val;
        diag45[j-i+n-1] = val;
        diag135[i+j] = val;
    }
};
