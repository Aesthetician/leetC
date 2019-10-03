class Solution {
public:
    bool isPalindrome(string s) {
        /*
        1. convert char to uppercase and ignore char which is not alphanumeric
        */
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (!isValid(s[left])) {
                left++;
            } else if (!isValid(s[right])) {
                right--;
            } else {
                if (toupper(s[left]) != toupper(s[right])) return false;
                left++;
                right--;
            }
        }
        return true;
    }
    
    bool isValid(char a) {
        if ((a >= '0' && a <= '9') || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) return true;
        return false;
    }
};
