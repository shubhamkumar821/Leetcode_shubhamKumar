class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if(n == 0) return 0;

        sort(intervals.begin(), intervals.end());

        int cnt = 0;
        int prev_int = intervals[0][1];

        for(int i = 1; i < n; i++) {

            if(prev_int > intervals[i][0]) {
                // overlap
                cnt++;
                prev_int = min(prev_int, intervals[i][1]);
            }
            else {
                // no overlap
                prev_int = intervals[i][1];
            }
        }

        return cnt;
    }
};