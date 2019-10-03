class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
        1. find leftmost
        xxxxxxMxxx
           T     R
           T < M or T==M continue shif R to the left;
        when L=R, we reach the leftmost target 
        M = lowbound of (L+R)/2
        M = L if R=L+1
        xxxTxxx
          LR
          M
        at this moment L->M+1 then => L=R
        2. find rightmost
        xxxxMxxxx
            T 
                R
             L=m+1 
        xxxTxxx
           LR
           M
        at this moment L->M+1 and N(L)!=T   
        3. corner case 
        a. N.size() = 1
        b. [T,T,T,T]
        c. [x,x,x]
        x < T => L = num.size()
        */
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        //part a.
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target <= nums[mid]) right = mid;
            else left = mid + 1;
        }
        //cout << left << endl;
        if (left == nums.size() || nums[left] != target) return res;
        res[0] = left;
        //part b.
        left = 0;
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid]) right = mid;
            else left = mid + 1;
        }
        //cout << left << endl;
        res[1] = left - 1;
        return res;
    }
};

class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        int left = lowboundBS(target, nums);
        if (left == nums.size() || nums[left] != target) return res;
        res[0] = left;
        int right = lowboundBS(target + 1, nums) - 1;
        res[1] = right;
        return res;
    }
    
    int lowboundBS(int target, vector<int>& nums) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target <= nums[mid]) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
