class Solution {
public:
    int knightDialer(int N) {
        static const int MOD = 1000000007;
        vector<vector<int>> graph = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, 
                                     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        vector<int> cnt(graph.size(), 1);
        int total = 10;
        for (int k = 1; k < N; ++k) {
            vector<int> nxtCnt(graph.size(), 0);
            int nxtTotal = 0;
            for (int i = 0; i < graph.size(); ++i) {
                for (int j = 0; j < graph[i].size(); ++j) {
                    int nd = graph[i][j];
                    nxtCnt[i] = (nxtCnt[i] + cnt[nd]) % MOD;
                }
                nxtTotal = (nxtTotal + nxtCnt[i]) % MOD; 
            }
            cnt = nxtCnt;
            total = nxtTotal;
        }
        return total;
    }
};
