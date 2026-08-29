class Solution {
public:
vector<int>dp;
int n;
    bool canJump(vector<int>& nums) {
        n=nums.size();
        dp.assign(nums.size()+1,-1);
        return rec(0,nums);
        
    }
    bool rec(int i,vector<int>& nums){

        if(i>=n-1){
            return true;
        }
        bool ans=false;
        if(dp[i]!=-1)return dp[i];

        for(int j=i+1;j<=min(n-1 ,i+nums[i]);j++){
            ans=ans||rec(j,nums);
              
        }
        return dp[i]=ans;
    }
};