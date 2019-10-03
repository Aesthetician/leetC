class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> nodes(n - 1, -1);
        vector<int> res;
        for (int i = 0; i < edges.size(); ++i) {
            int root1 = u_find(edges[i][0], nodes); 
            int root2 = u_find(edges[i][1], nodes);
            if (root1 == root2) res.push({edges[i][0], edges[i][1]});
            else u_union(root1, root2);
        }
        return res.back();
    }
    void u_find(int nd, vector<int>& nodes) {
        int prt = nodes[nd];
        while (nodes[prt] != -1) {
            prt = nodes[prt];
        }
        return prt;
    }
    void u_uion(int root1, int root2, vector<int>& nodes) {
        nodes[root2] = root1;
    }
};
