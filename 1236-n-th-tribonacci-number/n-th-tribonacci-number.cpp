class Solution {
public:
    int tribonacci(int n) {
        int dp[10100];
        memset(dp,-1,sizeof(dp));
    return fib(n,dp);
        
    }
    int fib(int n,int dp[]){
        if(n==0){
            return 0;
        }
         if(n==1){
            return 1;
        }
        if(n==2){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
     dp[n]= fib(n-1,dp) + fib(n-2,dp) + fib(n-3,dp);
     return dp[n];
    }
};