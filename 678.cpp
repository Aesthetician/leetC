class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, upper = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                low++;
                upper++;
            } else if (s[i] == ')') {
                low--;
                upper--;
            } else {
                low--;
                upper++;
            } 
            if (upper < 0) return false; 
            low = max(low, 0);
        }
        return low == 0;
    }
};
