class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        /*
        1. build graph
        2. dfs to detect cycle. 
        */
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> done(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!done[i] && dfsCycleDetect(i, graph, visited, done)) 
                return false;
        }
        return true;
    }
    
    vector<vector<int>> buildGraph(const int numCourses, const vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        return graph;
    }
    
    bool dfsCycleDetect(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& done) {
        if(!done[node] && visited[node]) return true;
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); ++i) {
            if (!done[graph[node][i]] && dfsCycleDetect(graph[node][i], graph, visited, done)) 
                return true;
        }
        done[node] = true;
        return false; 
    }
};
