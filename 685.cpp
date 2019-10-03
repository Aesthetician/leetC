class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        /*
         * 1. if a node has two parents, one of its edge should be remove to form a valid tree.
         * 2. there should be no cycle in the valid tree
         * 3. we have 3 cases
         * 3.1 a node has two parents and there is no cycle
         * 3.2 a node has two parents and there is a cycle 
         * ? why edge A should be in the cycle?
         * we follow the sequence of edges. if there is a cycle, there must an edge in the cycle. 
         * */
        
    }
};
