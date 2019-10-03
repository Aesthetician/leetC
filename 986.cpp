/*
986. Interval List Intersections
@ 7.24.2019
*/

        /*
        A [ ] [ ] [ ]
        i1 |
        B [ ] [ ] [ ]
        i2     |
        one on one merge
        Ex: 
        A [    ] 
        B  [ ]   [  ]
        res[ ] 
        so we can throw B[i2] and move to B[i2+1]
        A [    ]
        B        [  ]
        res    ] [
        invalid intersection 
       */

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        /*
        1. check if the intersection is valid.
        2. throw the interval with smaller end time.
        
        A [       ]   [ ]
        t=0 i1   
        t=1
        t=2           i1
        t=3
        B   [ ] [  ] [ ]
        t=0 i2
        t=1     i2
        t=2
        t=3          i2
        R   [ ] [ ] 
        */
        
        /*
        A [ ] [ ] [ ]
        i1 |
        B [ ] [ ] [ ]
        i2     |
        one on one merge
        Ex: 
        A [    ] 
        B  [ ]   [  ]
        res[ ] 
        so we can throw B[i2] and move to B[i2+1]
        A [    ]
        B        [  ]
        res    ] [
        invalid intersection 
       */
        vector<vector<int>> res; 
        int i1 = 0, i2 = 0;        
        while (i1 < A.size() && i2 < B.size()) {
            int start = max(A[i1][0], B[i2][0]);
            int end = min(A[i1][1], B[i2][1]);
            //check if the intersction is valid or not
            if (start <= end) res.push_back({start, end});
            if (A[i1][1] < B[i2][1]) {
                i1++;
            } else {
                i2++;
            }
        }
        return res;
    }
};

