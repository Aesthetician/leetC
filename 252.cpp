//252. Meeting Rooms
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
static bool CustCompare(const Interval& a, const Interval& b) {
    return a.start < b.start;
}
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        /*
        ex:
        Input: [[0,30],[5,10],[15,20]]
        30 10 20
        0   5 15
        T: O(nlogn)
        */
        sort(intervals.begin(), intervals.end(), CustCompare);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i-1].end) return false;
        }
        return true;
    }
};


class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        /*
        build a time line 
        ex: 0 5 10 15 20 30
            + + -   + -  -  
              False
        ex: Input: [[7,10],[2,4]]
            2 4 7 10
            + - + -
        
        T: O(N)
        S: O(max-min)
        */
        if (intervals.empty()) return true;
        int max_val = intervals[0].start;
        int min_val = intervals[0].end;
        for (int i = 0; i < intervals.size(); ++i) {
            max_val = max(max_val, intervals[i].end);
            min_val = min(min_val, intervals[i].start);
        }
        vector<int> timeline(max_val - min_val + 1, 0);
        for (int i = 0; i < intervals.size(); ++i) {
            timeline[intervals[i].start - min_val]++;
            timeline[intervals[i].end - min_val]--;
        }
        int sum = 0;
        for (int i = 0; i < timeline.size(); ++i) {
            sum += timeline[i];
            if (sum > 1) return false;
        }
        return true;
    }
};


class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        /*
        T: O(N+NlogN) NlogN is from map
        S: O(2*N)
        */
        map<int,int> timeline;
        for (int i = 0; i < intervals.size(); ++i) {
            timeline[intervals[i].start]++;
            timeline[intervals[i].end]--;
        }
        int sum = 0;
        for (auto it = timeline.begin(); it != timeline.end(); ++it) {
            sum += it->second;
            cout << sum << endl;
            if (sum > 1) return false;
        }
        return true;
    }
};
