class Solution {
public:
    int myAtoi(string str) {
        /*
        1. disgard whitespace characters in the beginning
        2. check sign  
        3. stop condition 
            a. non-digit characters
            b. out of range of 32-bit signed interger
        */
        int res = 0, start = 0, sign = 1;
        while (str[start] == ' ') start++;
        cout << start << endl;
        for (int i = start; i < str.size(); ++i) {
            if (i == start && str[i] == '+') continue;
            if (i == start && str[i] == '-') {
                sign = -1;
                continue;
            }
            if (str[i] - '0' < 0 || str[i] - '0' > 9) break;
            if (res > INT_MAX / 10 || INT_MAX - res * 10 < str[i] - '0') {
                if (sign == -1) return INT_MIN;
                else return INT_MAX;
            } else {
                cout << str[i] << endl;
                cout << res << endl;
                res = res * 10 + (str[i] - '0');
            }
        }
        return sign == 1 ? res : (res == INT_MAX ? INT_MIN : -1 * res);
    }
};
