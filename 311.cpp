//311. Sparse Matrix Multiplication

//partially calculation
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        /*
        A*B = C
        traverse A and calculate C partially 
        A           B               C
        
        [i][j]  *  [j][0] [j][1]  = C[i][0] C[i][1] ... 
        A: M*N
        B: N*NB
        T: O(M*N*Ratio(nonZero in A)*NB)
        */
        vector<vector<int>> C(A.size(), vector<int> (B[0].size(), 0));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                if (A[i][j] != 0) {
                    for (int k = 0; k < B[0].size(); ++k) {
                        if (B[j][k] != 0) C[i][k] += A[i][j] * B[j][k];
                    }
                }
            }
        }
        return C;
    }
};


//sparse matrix + partially calculation
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        /*
        sparse matrix respresentation
        http://www.cs.cmu.edu/~scandal/cacm/node9.html
        http://www.cnblogs.com/grandyang/p/5282959.html
        calculate C partially
        */
        vector<vector<int>> C(A.size(), vector<int> (B[0].size(), 0));
        vector<vector<int>> idxA(A.size(), vector<int> ());
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                if(A[i][j] != 0) idxA[i].push_back(j);
            }
        }
        for (int i = 0; i < idxA.size(); ++i) {
            for (int j = 0; j < idxA[i].size(); ++j) {
                int idx = idxA[i][j];
                for (int k = 0; k < B[0].size(); ++k) {
                    if (B[idx][k] != 0) {
                        C[i][k] += A[i][idx] * B[idx][k];
                    }
                }
            }
        }
        return C;
    }
};
