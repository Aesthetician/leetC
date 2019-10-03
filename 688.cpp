class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        /*
        123
        456
        789
      pre  now
        1->8
        3->8
        */
        vector<vector<int>> dir{{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
        vector<vector<double>> map(N, vector<double> (N,0));
        map[r][c] = 1;
        for (int k = 1; k <= K; ++k) {
            vector<vector<double>> nextMap(N, vector<double> (N,0));
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    nextMap[i][j] = mapProb(i, j, map, dir);
                }
            }
            map = nextMap;
        }
        double res = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                res += map[i][j];
            }
        }
        return res;
    }
    
    double mapProb(int y, int x, const vector<vector<double>>& map, const vector<vector<int>>& dir) {
        double res = 0;
        for (int i = 0; i < dir.size(); ++i) {
            int pre_x = x - dir[i][1];
            int pre_y = y - dir[i][0];
            if (pre_x > -1 && pre_x < map[0].size() && pre_y > -1 && pre_y < map.size())
                res += map[pre_y][pre_x] / 8;
        }
        return res;
    }
    
    
};
