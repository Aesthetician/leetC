class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag45(2 * n - 1, false);
        vector<bool> diag135(2 * n - 1, false);
        int cnt = 0;
        helper(0, cnt, col, diag45, diag135, n);
        return cnt;
    }
    void helper(int i, int& cnt, vector<bool>& col, vector<bool>& diag45, vector<bool>& diag135, int n) {
        if (i == n) {
            cnt++;
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (isNotAvailable(i, j, col, diag45, diag135, n)) continue;
            update(i, j, col, diag45, diag135, true, n);
            helper(i + 1, cnt, col, diag45, diag135, n);
            update(i, j, col, diag45, diag135, false, n);
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
