class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        /*
        s: "cbaebabacd" p: "abc"
        L   | 
        R   |
        dict : cnt for each char of p
        intuitively : valid pattern occurs when all the value of dict become zero and window lengh = p.size
        However, it costs time to check the result in dict
        alternative:
        total remainding cnt : p's char not yet in dict
        when total cnt == 0, it means p's char are all in dict
        dict helps us to detect if char is valid in p or not. 
        */
        vector<int> res;
        vector<int> dict(26, 0);
        for (int i = 0; i < p.size(); ++i) {
            int idx = p[i] - 'a';
            dict[idx]++;
        }
        int left = 0, right = 0, cnt = p.size();
        while (right < s.size()) {
            int ridx = s[right] - 'a';
            if (dict[ridx] > 0) cnt--;
            dict[ridx]--;    
            if (cnt == 0) res.push_back(left);
            if (right - left + 1 == p.size()) {
                int lidx = s[left] - 'a';
                dict[lidx]++;
                if (dict[lidx] > 0) cnt++;
                left++;
            }
            right++;
        }
        return res;
    }
};
