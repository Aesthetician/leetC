class Solution {
public:
    string addBinary(string a, string b) {
        int ai = a.size() - 1;
        int bi = b.size() - 1;
        string ans;
        int carry = 0;
        while (ai > -1 || bi > -1 || carry) {
            int da = ai > -1 ? a[ai] - '0' : 0;
            int db = bi > -1 ? b[bi] - '0' : 0;
            int sum = (da + db + carry) % 2;
            carry = (da + db + carry) / 2;
            ans = to_string(sum) + ans;
            ai--;
            bi--;
        }
        return ans;
    }
};
