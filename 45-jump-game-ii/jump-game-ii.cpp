class Solution {
public:
vector<int>dp;
int n;
    int jump(vector<int>& nums) {
        n=nums.size();
        dp.assign(nums.size()+1,-1);
        int ans=rec(0,nums);
        return ans;
        
    }

    int rec(int i,vector<int>&nums){
        if(i>=n-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=1e5;

        for(int j=i+1;j<=min(n-1 ,i+nums[i]);j++){
            ans=min(ans,1+rec(j,nums));
        }
       return dp[i]=ans;
    }
};