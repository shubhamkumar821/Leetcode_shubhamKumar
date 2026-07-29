class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0;
        int r = n - 1;
        int t = 0;
        int b = n - 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int cnt = 1;
        while (t <= b && l <= r) {
            for (int i = l; i <= r; i++) {
                ans[t][i] = cnt;
                cnt++;
            }
            t += 1;
            for (int j = t; j <= b; j++) {
                ans[j][r] = cnt;
                cnt++;
            }
            r -= 1;

            if (t <= b) {
                for (int k = r; k >= l; k--) {
                    ans[b][k]=cnt;
                    cnt++;
                }
                b -= 1;
            }
            if (l <= r) {
                for (int i = b; i >= t; i--) {
                    ans[i][l] = cnt;
                    cnt++;
                }
                l += 1;
            }
        }
        return ans;
    }
};