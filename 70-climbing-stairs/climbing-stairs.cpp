class Solution {
public:
int dp[100];
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,n);
        
        
    }
    int rec(int st,int n){
        if(st==n){
            return 1;
        }
        if(st>n){
            return 0;
        }
        if(dp[st]!=-1){
            return dp[st];
        }
        
        int ans=0;
         ans+=(rec(st+1,n)+rec(st+2,n));
         return dp[st]= ans;
    }
};