class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    	int pre = -1;
    	int max_val = 0;

    	for (int i = 0; i < seats.size(); ++i)
    	{    
            if (seats[i] == 1) {
    	        if (pre == -1) max_val = i;
    		else max_val = max(max_val, (i - pre) / 2);
                pre = i;
            }
            if (seats[i] == 0 && i == seats.size() - 1)
    	        max_val = max(max_val, i - pre);
    	}
        
        return max_val;
    }
};
