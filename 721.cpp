class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        /*
        account lsit
        a1:e1, e2
        a2:e2
        a3:e3
        connection  
        e1: a1, a2
        e2: a1, a3
        e3: a3
        
        graph
           *      *
        e1-a1-e2 a3-e3
        /   
       a2 
        
        1. build a graph, email-account; we already have account-list of email
        2. dfs to record the connected components
        T(n) = sum of ai * log(ai)
        S(n) = sum of ai (ai = the length of accounts[i])
        */
        unordered_map<string, vector<int>> conn = buildConn(accounts);
        vector<int> visited(accounts.size(), false);
        vector<vector<string>> res;
        for (int i = 0; i < accounts.size(); ++i) {
            if (visited[i]) continue;
            set<string> elist;
            dfs(i, elist, visited, conn, accounts);
            vector<string> emails(elist.begin(), elist.end());
            emails.insert(emails.begin(), accounts[i][0]);
            res.push_back(emails);
        }
        return res;
    }
    
    unordered_map<string, vector<int>> buildConn(const vector<vector<string>>& accounts) {
        unordered_map<string, vector<int>> res;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                res[accounts[i][j]].push_back(i);
            }    
        }
        return res;
    }
    
    void dfs(int node, set<string>& elist, vector<int>& visited, unordered_map<string, vector<int>>& conn, const vector<vector<string>>& accounts) {
        visited[node] = true;
        for (int i = 1; i < accounts[node].size(); ++i) {
            string email = accounts[node][i]; 
            elist.insert(email);
            vector<int> ndList = conn[email];
            for (int j = 0; j < ndList.size(); ++j) {
                if (!visited[ndList[j]]) dfs(ndList[j], elist, visited, conn, accounts);
            }
        }
    }
};
