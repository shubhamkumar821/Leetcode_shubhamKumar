class Solution {
public:
vector<vector<int>>dp;
    int rob(vector<int>& nums) {
      int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        dp.assign(nums.size()+1,vector<int>(sum+1,-1));
        return rec(0,0,nums);



        
    }
    int rec(int i,int sum,vector<int>&nums){
        if(i>=nums.size())return 0;
        if(dp[i][sum]!=-1)return dp[i][sum];


        int ans=INT_MIN;
        int take=rec(i+2,sum+nums[i],nums)+nums[i];
        int dtake=rec(i+1,sum,nums);

        ans=max(take,dtake);

      return  dp[i][sum]=ans;


    }
};