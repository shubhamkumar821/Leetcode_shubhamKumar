class Solution {
public:
int total;
int n;
int dp[210][21000];
    bool canPartition(vector<int>& nums) {
        int sum=0;
        n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        total =sum;
        
      for(int i=0;i<nums.size();i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=-1;
        }
      }
        return rec(0,0,nums);

        
    }
    int rec(int i,int sum,vector<int>&nums){
        if(i==n){
            if(sum==(total-sum)){
                return 1;
            }
            else {
                return 0;
            }
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
      int ans= rec(i+1,sum,nums);

      if(ans==1){
        return 1;
      }
      else {
        ans=rec(i+1,sum+nums[i],nums);
      }
      return dp[i][sum]=ans;


    }
};
