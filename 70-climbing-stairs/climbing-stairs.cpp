class Solution {
public:
    int climbStairs(int n) {
        int ans=0;
        int dp[101000];
        memset(dp,-1,sizeof(dp));
       return rec(n,0,dp);
        
        
    }
    int rec(int n,int lev,int dp[])
    {
           if(lev>n){
            return 0;
           }
           if(dp[lev]!=-1){
            return dp[lev];
           }
        if(lev==n){
            return 1;

        }
        dp[lev]=rec(n,lev+1,dp)+rec(n,lev+2,dp);
        
        return rec(n,lev+1,dp)+rec(n,lev+2,dp);
    }
};