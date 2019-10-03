//Time complexity: O(mn)
//Space: O(mn)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n,1));
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                v[i][j] = v[i-1][j] + v[i][j-1];
            }
        }
        return v[m-1][n-1];
    }
};

//improvement on space complexity
//Time complexity: O(mn)
//Space: O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> d(n,1);
        /*
        pre row: d[j-1]  d[j]
        crt row: d[j-1]  "update d[j] here"!
        
        d[j-1]  old d[j] 
        ----------------
        d[j-1]  new d[j] 

        d[j] = d[j-1] + d[j](old one)
        */
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                d[j] = d[j-1] + d[j];
            }
        }
        return d[n-1];
    }
};


