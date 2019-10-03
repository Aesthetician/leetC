//253. Meeting Rooms II
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
        T: O(NlogN)
        S: O(N)
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


class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        /*
        this approch works better if max-min < # of intervals
        T: O(N)
        S: O(max-min)
        */
        if (intervals.empty()) return 0;
        int max_val = intervals[0].end;
        int min_val = intervals[0].start;
        for (int i = 0; i < intervals.size(); ++i) {
            max_val = max(max_val, intervals[i].end);
            min_val = min(min_val, intervals[i].start);
        }
        vector<int> timeline(max_val - min_val + 1, 0);
        for (int i = 0; i < intervals.size(); ++i) {
            timeline[intervals[i].start-min_val]++;
            timeline[intervals[i].end-min_val]--;
        }
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < timeline.size(); ++i) {
            cnt += timeline[i];
            ans = max(ans, cnt);
        }
        return ans;
    }
};


class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        /*
        use a map to represent a time line
        T: O(NlogN)
        S: O(N)
        */
        map<int, int> timeline;
        for (int i = 0; i < intervals.size(); ++i) {
            timeline[intervals[i].start]++;
            timeline[intervals[i].end]--;
        }
        int cnt = 0;
        int ans = 0;
        for (auto it = timeline.begin(); it != timeline.end(); ++it) {
            cnt += it->second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};


//https://github.com/jiadaizhao/LeetCode/blob/master/0253-Meeting%20Rooms%20II/0253-Meeting%20Rooms%20II.cpp
//https://blog.csdn.net/yurenguowang/article/details/76665171
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        /*
        T: O(NlongN)
        S: O(N)
        */
        vector<pair<int, int>> timeline;
        for (int i = 0; i < intervals.size(); ++i) {
            timeline.push_back(make_pair(intervals[i].start, 1));
            timeline.push_back(make_pair(intervals[i].end, -1));
        }
        sort(timeline.begin(), timeline.end());
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < timeline.size(); ++i) {
            cnt += timeline[i].second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};


struct CustCompare {
   bool operator()(const int &a, const int &b) {
       return a > b;
   }
};
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        /*
        use a priority queue
        Input: [[0, 30],[5, 10],[15, 20]]
        t=0
        pq: 30
        t=1
        pq: 10 30
        t=2
        pq: 20 30
        T:O(NlogN)
        S:O(N)
        */
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), myCompare);
        priority_queue<int, vector<int>, CustCompare> pq;//default is max-heap!
        pq.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); ++i) {
            if (!pq.empty() && intervals[i].start >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
    static bool myCompare(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
};
