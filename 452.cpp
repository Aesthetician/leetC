class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        /*
        [[10,16], [2,8], [1,6], [7,12]]
        6 8 12 16
        1 2 7  10
        T: O(NlogN)
        */
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), myCompare);
        int last = points[0].second;
        int cnt = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i].first > last) {
                last = points[i].second;
                cnt++;
            } else {
                last = min(last, points[i].second);
            }
        }
        return cnt;
    }
    static bool myCompare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};
