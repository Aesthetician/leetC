// 29. Divide Two Integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = 1;
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) sign = -1;
        long long dvd = labs(dividend);
        long long div = labs(divisor);
        int ans = 0;
        while (dvd >= div) {
            int shift = 0;
            while (dvd > 2 * div) {
                div = div << 1;
                shift++;
            }
            dvd -= div;
            ans += 1 << shift;
            div = labs(divisor);
        }
        return (sign > 0) ? ans : -ans; 
    }
};
