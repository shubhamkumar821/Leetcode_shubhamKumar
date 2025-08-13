class Solution {
    vector<vector<int>>dp;
    int totalsum;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalsum=accumulate(nums.begin(),nums.end(),0);
        dp=vector<vector<int>>(nums.size(),vector<int>(2*totalsum+1,INT_MIN));
        return rec(0,0,target,nums);

        
    }
    int rec(int lev,int sum,int target,vector<int>& nums){
        if(lev==nums.size() && sum==target){
            return 1;
        }
        if(lev==nums.size() && sum!=target){
            return 0;
        }
        if(dp[lev][totalsum+sum]!=INT_MIN){
            return dp[lev][totalsum+sum];
        }
        int ans=rec(lev+1,sum+nums[lev],target,nums)+rec(lev+1,sum-nums[lev],target,nums);
        dp[lev][totalsum+ sum]=ans;
        return ans;
    }
};
