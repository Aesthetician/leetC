class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<int> idx(2, 0);
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for (int i = n - 1; i > -1; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i < 3 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if (j - i > idx[1] - idx[0]) {
                        idx[0] = i;
                        idx[1] = j; 
                    }
                }
            }
        }
        return s.substr(idx[0], idx[1] - idx[0] + 1);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int max_len = 1;
        for (int i = 0; i < n; ++i) {
            expending(s, i, i, start, max_len);
            expending(s, i, i + 1, start, max_len);
        }
        return s.substr(start, max_len);
    }
    void expending(string s, int i, int j, int &start, int &max_len) {
        while (i > -1 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        if (j - i - 1 > max_len) {
            max_len = j - i - 1;
            start = i + 1;
        }
    }
};
