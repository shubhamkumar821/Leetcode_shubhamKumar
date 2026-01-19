class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int head = -1, tail = 0;
        int n = nums.size();
        unordered_map<int,int> mpp;
        long long sum = 0, ans = 0;
        int cnt = 0;

        while (tail < n) {

            // expand window
            while (head + 1 < n && mpp[nums[head + 1]] == 0 && cnt < k) {
                head++;
                mpp[nums[head]]++;
                sum += nums[head];
                cnt++;
            }

            // valid window
            if (cnt == k) {
                ans = max(ans, sum);
            }

            // shrink window
            if (head >= tail) {
                mpp[nums[tail]]--;
                sum -= nums[tail];
                cnt--;
                tail++;
            }

            // reset window safely
            if (tail > head) {
                head = tail - 1;
            }
        }
        return ans;
    }
};
