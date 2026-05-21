class Solution {
public:
    
    vector<int> dplen, dpcnt;
    int n;

    pair<int,int> rec(int i, vector<int>& nums) {

        // already calculated
        if(dplen[i] != -1) {
            return {dplen[i], dpcnt[i]};
        }

        int len = 1;
        int cnt = 1;

        for(int j = 0; j < i; j++) {

            if(nums[i] > nums[j]) {

                auto prev = rec(j, nums);

                // better length found
                if(prev.first + 1 > len) {
                    len = prev.first + 1;
                    cnt = prev.second;
                }

                // same length found again
                else if(prev.first + 1 == len) {
                    cnt += prev.second;
                }
            }
        }

        dplen[i] = len;
        dpcnt[i] = cnt;

        return {len, cnt};
    }

    int findNumberOfLIS(vector<int>& nums) {

        n = nums.size();

        dplen.assign(n, -1);
        dpcnt.assign(n, -1);

        int maxi = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {

            auto cur = rec(i, nums);

            // new maximum LIS
            if(cur.first > maxi) {
                maxi = cur.first;
                ans = cur.second;
            }

            // same maximum LIS
            else if(cur.first == maxi) {
                ans += cur.second;
            }
        }

        return ans;
    }
};