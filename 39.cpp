class Solution {
public:
    /*
    candidates: [2,3,6,7]; target = 7
    search tree:
    2 3 6 7
    | | | |
    | | | 7
    | | 6 7
    | 3 6 7
    2 3 6 7
    T(n) = TBD
    S(n) = TBD
    */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, tmp, res, target, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, vector<int>& tmp, vector<vector<int>>& res, int target, int start) {
        if (target < 0) return;
        if (target == 0) res.push_back(tmp);
        for (int i = start; i < candidates.size(); ++i) {
            if (target < candidates[i]) break;
            tmp.push_back(candidates[i]);
            backtrack(candidates, tmp, res, target - candidates[i], i);
            tmp.pop_back();
        }
    }
};
