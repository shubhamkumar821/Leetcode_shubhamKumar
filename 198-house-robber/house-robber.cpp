class Solution {
public:
  vector<int> dp;
    int rob(vector<int>& nums) {
      
        dp.resize(nums.size(),-1);
        
        int myans=rec(0,nums);
        return myans;
        
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
