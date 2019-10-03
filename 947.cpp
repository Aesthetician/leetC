/*

(0,2)   (2,2)
    (1,1)
(0,0)   (2,0)
remove: 3
point - connected component = 5 - 2 = 3

     (1,2)(2,2)
(0,1)     (2,1)
(0,0)(1,0)
remove: 5
point - connected component = 6 - 1 = 5
*/
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, int> graph = buildGraph(stones);
        int n_connected_component = dfs(stones, graph);
        return n - n_connected_component;
    }
    int dfs() {
    }

};
