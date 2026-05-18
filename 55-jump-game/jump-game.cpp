class Solution {
public:
    vector<int> dp;
    int n;

    bool canJump(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, -1);

        return rec(0, nums);
    }

    bool rec(int i, vector<int>& nums) {

        if (i >= n - 1) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        for (int j = 1; j <= nums[i]; j++) {

            if (rec(i + j, nums)) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }
};