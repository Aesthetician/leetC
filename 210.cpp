class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        /*
        1. build graph by 2D vector
        2. dfs with cycle detection and make topology sort 
        */
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> done(numCourses, false);
        vector<int> res;
        
        //dfs cycle detection + topology sort
        for (int i = 0; i < numCourses; ++i) {
            if (!done[i] && dfs(i, visited, done, graph, res)) 
                return vector<int> ();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    vector<vector<int>> buildGraph(const int numCourses, const vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        return graph;
    }
    
    bool dfs(const int node, vector<bool>& visited, vector<bool>& done, const vector<vector<int>>& graph, vector<int>& res) {
        if (!done[node] && visited[node]) return true;
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); ++i) {
            if (!done[graph[node][i]] && dfs(graph[node][i], visited, done, graph, res))
                return true;
        }
        done[node] = true;
        res.push_back(node);
        return false;
    }
    
};
