class Solution {
public:
  vector<int> dp;
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int n=nums.size();
      
        dp.resize(nums.size(),-1);
        vector<int> arr1, arr2;
    for (int i = 0; i < nums.size(); i++) {
        if (i != 0) arr1.push_back(nums[i]);
        if (i != nums.size() - 1) arr2.push_back(nums[i]);
    }
        dp.assign(n, -1);
        int ans1 = rec(0, arr1);

        dp.assign(n, -1);
        int ans2 = rec(0, arr2);

        return max(ans1, ans2);
        
    }
    int rec(int level,vector<int>& nums){
        if(level>=nums.size()){
            return 0;
        }

        int ans=rec(level+1,nums);
        if(dp[level]!=-1){
            return dp[level];
        }
        ans=max(ans,nums[level]+rec(level+2,nums));
        dp[level]=ans;
        return ans;
    }
};