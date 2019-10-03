/*
56. Merge Intervals
@ 7.24.2019
*/ 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
        1. sort the start time of the intervals.
        2. if the start time of the interval > the end time of the last merged interval, 
            -> push a new merge interval. 
           else
            -> choose the maximul end time. 
        
        Intervals:
          [   ]    [     ]
            [   ] [  ] [   ]
            
        R [   ]
        R [     ]
        R [     ] [  ]
        R [     ] [      ] 
        R [     ] [        ] 
        
        Time & Space:
        T: O(NlogN + N) = O(NlogN)
            1. sort the intervals 
            2. merge one by one
        S: O(N)  
        */
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        /*
        T: O(NlogN)
        S: O(N)
        */
        sort(intervals.begin(), intervals.end(), myCompare);
        /*
        sort(intervals.begin(), intervals.end(), [] (Interval a, Interval b) {
            return a.start < b.start;
        });
        */
        vector<Interval> res;
        int last = INT_MIN;
        for (int i = 0; i < intervals.size(); ++i) {
            if (last < intervals[i].start) {
                res.push_back(intervals[i]);
                last = intervals[i].end;
            } else {
                last = max(last, intervals[i].end);
                res.back().end = last;
            }
        }
        return res;
    }
    static bool myCompare(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
};


class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        vector<Interval> res;
        int i = 0;
        while (i < intervals.size()) {
            int start = intervals[i].start;
            int end = intervals[i].end;
            while (i + 1 < intervals.size() && end >= intervals[i+1].start) {
                i++;
                end = max(end, intervals[i].end);
            }
            res.push_back({start, end});
            i++;
        }
        return res;
    }
};
