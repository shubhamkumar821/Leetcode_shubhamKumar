class Solution {
public:
int dp[101010];
int n;
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        n=cost.size();
           return min(rec(0, cost), rec(1, cost));

        
    }
    int rec(int level,vector<int>&nums){
        if(level>=n){
            return 0;
        }
        if(dp[level]!=-1){
            return dp[level];
        }
        int ans=min(rec(level+1,nums)+nums[level],rec(level+2,nums)+nums[level]);
        return dp[level]=ans;
    }
};