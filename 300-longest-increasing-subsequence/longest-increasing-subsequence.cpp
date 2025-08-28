class Solution {
public:
    vector<int> arr;
    vector<vector<int>> dp;
    int n;

    int lengthOfLIS(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n+1, -1)); // dp[i][prevIdx+1]
        return rec(0, -1);
    }

    int rec(int i, int prevIdx) {
        if (i == n) return 0;

        if (dp[i][prevIdx+1] != -1) return dp[i][prevIdx+1];

        // Option 1: skip current element
        int ans = rec(i+1, prevIdx);

        // Option 2: take current element if valid
        if (prevIdx == -1 || arr[i] > arr[prevIdx]) {
            ans = max(ans, 1 + rec(i+1, i));
        }

        return dp[i][prevIdx+1] = ans;
    }
};
