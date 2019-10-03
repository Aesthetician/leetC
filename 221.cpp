/*
1. Brute force: 1+4+9+16+25 = O(N^3), N is side length
2. DP: O(N^2)
matrix
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

sizes
1 x 1 x x
1 x 1 1 1  //min(0, 1, 0) + 1 = 1
1 1 1 2 2  //min(1, 1, 1) + 1 = 2
1 x x 1 x
maxSize = 2

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        
        vector<vector<int>> sizes(m, vector<int> (n, 0));
        int maxSize = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(i==0 || j==0) 
                    sizes[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1')
                    sizes[i][j] = 1 + (min(sizes[i-1][j-1], min(sizes[i][j-1], sizes[i-1][j])));
                maxSize = max(sizes[i][j], maxSize);
                //printf("%4d ", sizes[i][j]);
            }
            //printf("\n");
        }
        return maxSize*maxSize;
    }
};

*/
