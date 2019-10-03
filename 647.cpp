class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if(n==0) return 0;
        
        int max = 1;
        
        for(int i = 1; i < n; i++){
            //odd
            int idx = 0;
            while(s[i + idx] == s[i - idx] && i - idx > -1 && i + idx < n){
                max += 1;
                idx += 1;
            }
            //even
            idx = 0;
            while(s[i - idx - 1] == s[i + idx] && i - idx -1 > -1 && i + idx < n){
                max += 1;
                idx += 1;
            }
        }
        return max;
    }
};
