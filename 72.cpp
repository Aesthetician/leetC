class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length()+1;
        int n = word2.length()+1;
        vector<vector<int>> c(m, vector<int>(n,0));
        
        int c_insert = 1;
        int c_delete = 1;
        int c_replace = 1;
        
        for(int i=1;i<m;i++) c[i][0] = c[i-1][0] + c_delete;
        for(int i=1;i<n;i++) c[0][i] = c[0][i-1] + c_insert;
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(word1[i-1]==word2[j-1]) c_replace = 0;
                else c_replace = 1;
                c[i][j]=min(c[i-1][j] + c_delete, min(c[i][j-1] + c_insert, c[i-1][j-1] + c_replace));
            }
        }
        return c[m-1][n-1];
    }
};
