struct cell {
    int val;
    int i;
    int j;
    cell (int x, int row, int col): val(x), i(row), j(col) {}
};
struct myCompare {
    bool operator()(const cell &a, const cell &b) {
        return a.val > b.val;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        /*
        Input:[
        [4,10,15,24,26], 
        [0,9,12,20], 
        [5,18,22,30]]
        t = 0
        pq: 0 4 5
        min, max: 0, 5
        t= 1
        pq: 4 5 9
        min, max: 4, 9
        t= 2
        pq: 5 9 10
        min, max: 5, 10
        
        T: O(nlogk)
        S: O(logk)
        */
        priority_queue<cell, vector<cell>, myCompare> pq;
        int max_val = nums[0][0];
        for (int i = 0; i < nums.size(); ++i) {
            cell item(nums[i][0], i, 0);
            pq.push(item);
            max_val = max(max_val, nums[i][0]);
        }
        int min_val = pq.top().val;
        vector<int> res{min_val, max_val};
        while (pq.top().j + 1 < nums[pq.top().i].size()) {
            cell item = pq.top();
            pq.pop();
            cell next(nums[item.i][item.j+1], item.i, item.j+1);
            pq.push(next);
            max_val = max(max_val, nums[item.i][item.j+1]);
            min_val = pq.top().val;
            //cout << min_val << ";" << max_val << endl;
            if (res[1] - res[0] > max_val - min_val) {
                res = {min_val, max_val};
            }
        }
        return res;
    }
};
