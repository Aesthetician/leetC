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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        /*
        3 condition
        1. newinterval is in the begin 
        2. newinterval is in the end
        3. newinterval is overlapped or not overlapped in the middle.
        */
        vector<Interval> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        int last = INT_MIN;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start > last) {
                if (newInterval.end < intervals[i].start) {
                    res.push_back(newInterval);
                    newInterval.start = INT_MAX;
                    newInterval.end = INT_MAX;
                }
                res.push_back(intervals[i]);
                last = intervals[i].end;                
            } else {
                last = max(last, intervals[i].end);
                res.back().end = last;
            }
            if (newInterval.start <= last) {
                res.back().start = min(newInterval.start, res.back().start);
                last = max(last, newInterval.end);
                res.back().end = last;
                newInterval.start = INT_MAX;
                newInterval.end = INT_MAX;
            }  
        }
        if (newInterval.start != INT_MAX && newInterval.start > res.back().end) res.push_back(newInterval);
        return res;
    }
};


//better approach
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        /*
        |---| |--| |----| |----| |--|
                |----------|
        T: O(N)
        S: O(N)
        */
        vector<Interval> res;
        int i = 0;
        while (i < intervals.size() && intervals[i].end < newInterval.start) {
            res.push_back(intervals[i]);
            i++;
        }
        while (i < intervals.size() && intervals[i].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            i++;
        }
        res.push_back(newInterval);
        while (i < intervals.size() && intervals[i].start > newInterval.end) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
