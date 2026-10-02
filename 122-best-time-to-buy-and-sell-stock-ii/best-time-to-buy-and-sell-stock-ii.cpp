class Solution {
public:
vector<vector<int>>dp;
int n;
    int maxProfit(vector<int>& prices) {
         n=prices.size();
        dp.assign(n+1,vector<int>(2,-1));
        return rec(0,prices,0);

        
        
    }
    int rec(int i,vector<int>&prices,int k){

        
        if(i==n )return 0;
        if(dp[i][k]!=-1)
        return dp[i][k];
       // int ans=0;
        int res=0;
         if(k==0){
            int take=rec(i+1,prices,1)-prices[i];
            int dontake=rec(i+1,prices,0);
             res=max(take,dontake);

            
         }
         else{
            int sell=rec(i+1,prices,0)+prices[i];
            int notsell=rec(i+1,prices,1);
            res=max(sell,notsell);
         }

return dp[i][k]=res;

    }
    
};