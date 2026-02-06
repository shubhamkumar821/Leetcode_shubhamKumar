class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        int ans = 0;

        for (int j = 0; j < n; j++) {
            while (i < n && nums[i] <= 1LL * nums[j] * k) {
                i++;
            }
            ans = max(ans, i - j);
        }

        return n - ans;
    }
};
