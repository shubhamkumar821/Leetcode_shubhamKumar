class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int st_col = 0;
        int end_col = m - 1;
        
        while (st_col <= end_col) {
            int max_row = 0;
            int mid_col = (st_col + end_col) / 2;

            // 1. Find the maximum element in the current column
            for (int row = 0; row < n; row++) {
                if (mat[row][mid_col] >= mat[max_row][mid_col]) {
                    max_row = row;
                }
            }

            // 2. Safely get left and right neighbors (use -1 if out of bounds)
            int left = (mid_col - 1 >= 0) ? mat[max_row][mid_col - 1] : -1;
            int right = (mid_col + 1 < m) ? mat[max_row][mid_col + 1] : -1;

            // 3. Check if it is a peak
            if (mat[max_row][mid_col] > left && mat[max_row][mid_col] > right) {
                return {max_row, mid_col};
            }
            // 4. Move to the right if the right neighbor is greater
            else if (mat[max_row][mid_col] < right) {
                st_col = mid_col + 1;
            }
            // 5. Otherwise, move to the left
            else {
                end_col = mid_col - 1;
            }
        }
        return {-1, -1};
    }
};