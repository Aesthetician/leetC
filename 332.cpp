//332. Reconstruct Itinerary
/*
https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C++
an Eulerian trail (or Eulerian path) is a trail in a finite graph which visits every edge exactly once.
for this problem, we have to visit each edge exactly once.
*/
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        /*
        n: # of node
        m: # of edge 
        T: O(NlogN + M)
        worst case: J->A, J->B, A->J, B->J 
        S: O(N)
        */
        unordered_map<string, multiset<string>> graph = buildGraph(tickets);
        vector<string> stk;
        dfs("JFK", graph, stk);
        reverse(stk.begin(), stk.end());
        return stk;
    }
    unordered_map<string, multiset<string>> buildGraph(vector<pair<string, string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (int i = 0; i < tickets.size(); ++i) {
            graph[tickets[i].first].insert(tickets[i].second);
        }
        return graph;
    }
    void dfs(string start, unordered_map<string, multiset<string>>& graph, vector<string>& stk) {
        while(!graph[start].empty()) {
            string next = *graph[start].begin();
            graph[start].erase(graph[start].begin());
            dfs(next, graph, stk);
        }
        stk.push_back(start);
    } 
};
