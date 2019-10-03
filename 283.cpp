class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        Input: [0,1,2,0,3,12]
        t=0
        idx0    |
        i         i
                1 0
        t=1    
        idx0      |
        i           i
                1 0
                  2 0
        t=2          
        idx0        |
        i               i
                1 0
                  2 0
        */
        int idx0 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[idx0], nums[i]);
                idx0++;
            }
        }
    }
};


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        Input: [0,1,0,3,12]
        i             |
        p               |
                1 0
                  3   0
                    12   0

        */
        int p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                p = i;
            } else {
                while (p + 1 < nums.size() && nums[p+1] == 0) p++;
                p++;
                if (p == nums.size()) break;
                swap(nums[i], nums[p]);
            }
        }
    }
};
