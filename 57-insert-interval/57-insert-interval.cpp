class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        // add all intervals that end before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            i++;
        }
        // merge all overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // insert the merged interval
        intervals.insert(intervals.begin() + i, newInterval);
        // remove any intervals that are completely covered by the merged interval
        while (i + 1 < intervals.size() && intervals[i + 1][0] <= newInterval[1]) {
            intervals.erase(intervals.begin() + i + 1);
        }
        // remove any intervals that overlap with the merged interval
        while (i > 0 && intervals[i - 1][1] >= newInterval[0]) {
            newInterval[0] = min(newInterval[0], intervals[i - 1][0]);
            newInterval[1] = max(newInterval[1], intervals[i - 1][1]);
            intervals.erase(intervals.begin() + i - 1);
            i--;
        }
        // update the merged interval in place
        intervals[i] = newInterval;
        return intervals;
    }
};
