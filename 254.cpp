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
    int minMeetingRooms(vector<Interval>& intervals) {
        /*
        sort start and end 
        [[0, 30],[5, 10],[15, 20]]
        0  5  15
        10 20 30
        */
        if (intervals.empty()) return 0;
        vector<int> start;
        vector<int> end;
        for (int i = 0; i < intervals.size(); ++i) {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int eidx = 0;
        int res = 1;
        for (int i = 1; i < start.size(); ++i) {
            if (start[i] < end[eidx]) res++;
            else eidx++;
        }
        return res;
    }
};
