class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int a = intervals[i][0];
            int b = intervals[i][1];
            bool covered = false;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int c = intervals[j][0];
                int d = intervals[j][1];

                // Is interval i covered by interval j?
                if ((c <= a && d >= b) && (c < a || d > b)) {
                    covered = true;
                    break;
                }
            }

            if (!covered)
                ans++;
        }

        return ans;
    }
};