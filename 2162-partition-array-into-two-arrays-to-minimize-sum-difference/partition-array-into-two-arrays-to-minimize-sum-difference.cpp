class Solution {
public:
    void generate(vector<int>& nums, int idx, int end,
                  int cnt, long long sum,
                  vector<vector<long long>>& store) {

        if (idx == end) {
            store[cnt].push_back(sum);
            return;
        }

        // Don't take nums[idx]
        generate(nums, idx + 1, end, cnt, sum, store);

        // Take nums[idx]
        generate(nums, idx + 1, end, cnt + 1, sum + nums[idx], store);
    }

    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int m = n / 2;

        long long total = 0;
        for (int x : nums) total += x;

        vector<vector<long long>> left(m + 1), right(m + 1);

        // Recursively generate subset sums
        generate(nums, 0, m, 0, 0, left);
        generate(nums, m, n, 0, 0, right);

        // Sort right-half sums
        for (int i = 0; i <= m; i++)
            sort(right[i].begin(), right[i].end());

        long long ans = LLONG_MAX;

        for (int k = 0; k <= m; k++) {

            for (long long s1 : left[k]) {

                int need = m - k;

                long long target = total / 2 - s1;

                auto &v = right[need];
                auto it = lower_bound(v.begin(), v.end(), target);

                if (it != v.end())
                    ans = min(ans,
                              llabs(total - 2 * (s1 + *it)));

                if (it != v.begin()) {
                    --it;
                    ans = min(ans,
                              llabs(total - 2 * (s1 + *it)));
                }
            }
        }

        return (int)ans;
    }
};