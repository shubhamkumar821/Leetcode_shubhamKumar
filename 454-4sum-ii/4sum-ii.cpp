class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                     vector<int>& nums3, vector<int>& nums4) {
        
        map<int, int> mp;
        int ans = 0;

        // nums1 + nums2
        for (int a : nums1) {
            for (int b : nums2) {
                mp[a + b]++;
            }
        }

        // nums3 + nums4
        for (int c : nums3) {
            for (int d : nums4) {
                ans += mp[-(c + d)];
            }
        }

        return ans;
    }
};


