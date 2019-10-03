//https://www.jianshu.com/p/c382f25c06d9

class Solution {
public:
    string alienOrder(vector<string>& words) {
        /*
        1. extract edge from the words list 
        2. build graph
        3. dfs to detect cycle and topology sort
        */
        const int n = 26;
        vector<vector<int>> graph = buildGraph(n, words);
        vector<bool> visited(n, false);
        vector<bool> done(n, false);
        vector<bool> nodes = getNodes(n, words);
        string res;
        for (int i = 0; i < n; ++i) {
            if (nodes[i] && !done[i] && dfs(i, graph, visited, done, res)) 
                return "";
        }
        return res;        
    }
    
    vector<bool> getNodes(const int n, const vector<string>& words) {
        vector<bool> nodes(n, false);
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                nodes[words[i][j]-'a'] = true;
            }
        }
        return nodes;
    }
    
    vector<vector<int>> buildGraph(const int n, const vector<string>& words) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < words.size() - 1; ++i) {
            int prefixIdx = getPrefixIdx(words[i], words[i+1]);
            if (prefixIdx + 1 < words[i].size() && prefixIdx + 1 < words[i+1].size()) {
                //get node 
                int u = words[i][prefixIdx+1] - 'a';
                int v = words[i+1][prefixIdx+1] - 'a';
                //add edge
                graph[u].push_back(v);
            }
        }
        return graph;
    }
    
    int getPrefixIdx(string a, string b) {
        int idx = -1;
        for (int i = 0; i < a.size() && i < b.size(); ++i) {
            if (a[i] != b[i]) return idx;
            idx = i;
        }
        return idx;
    }
    
    bool dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& done, string& res) {
        if (visited[node] && !done[node]) return true;
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); ++i) {
            if (!done[graph[node][i]] && dfs(graph[node][i], graph, visited, done, res)) return true;
        }
        done[node] = true;
        res = (char) ('a' + node) + res; 
        return false;
    }
};
