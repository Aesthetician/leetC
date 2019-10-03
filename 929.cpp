class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        /*
        version 0:
        1. for each string, use find() to get the position of '@', and then get local name and domain name.
        2. process the local name and concatenate with the domain name, and then store it into a set.
            2.1 use find() to get the position of '+', and then skip the string following '+'
            2.2 use find() to get the position of '.', and then remove the '.'
        3. the size of the set is the answer. 
        
        version 1:
        T = O(M*N)
        S = O(N)
        1. scan each string character by character.
            1.1 skip '.'
            1.2 skip '+' and everything beyond it in the local name
            1.3 keep '@' and all the string beyond it
        2. use set to record the sting
        */
        unordered_set<string> hset;
        for (int i = 0; i < emails.size(); ++i) {
            string sout = processing(emails[i]);
            hset.insert(sout);
        }
        return hset.size();
    }
    string processing(const string &s) {
        string sout;
        bool is_local = true;
        bool skip = false;
        for (int i = 0; i < s.size(); ++i) {
            if (is_local && s[i] == '.') continue;
            if (s[i] == '+') skip = true;
            if (s[i] == '@') is_local = false;
            if (is_local && skip) continue;
            sout += s[i];
        }
        return sout;
    }
};
