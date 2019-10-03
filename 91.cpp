class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || (s.size() > 1 && s[0] == '0')) return 0;
        vector<int> dp(s.size() + 1, 1);
        for (int i = 1; i < dp.size(); ++i) {
            int idx = i - 1;
            if (s[idx] == '0') dp[i] = 0;
            else dp[i] = dp[i-1];
            if(i > 1 && ( s[idx-1] == '1' || s[idx-1] == '2' && s[idx] < '7')) {
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || (s.size() > 1 && s[0] == '0')) return 0;
        int crt = 1;
        int pre = 1;
        for (int i = 0; i < s.size(); ++i) {
            int tmp = crt;
            if (s[i] == '0') {
                crt = 0;
            }
            if (i > 0 && ( s[i-1] == '1' || s[i-1] == '2' && s[i] < '7')) {
                crt += pre;
            }
            pre = tmp;
        }
        return crt;
    }
};
