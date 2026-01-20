class Solution {
public:
int n;
    int maxProfit(vector<int>& prices) {
       vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
         n=prices.size();
        return rec(0,1,prices,dp);
        
    }
    int rec(int i,int buying,vector<int>&prices,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][buying]!=-1){
            return dp[i][buying];
        }
        int ans=rec(i+1,buying,prices,dp);;
        if(buying){
          
           int buy= rec(i+1,0,prices,dp)-prices[i];


    ans=max(buy,ans);

        }
        else{
         int sell=rec(i+2,1,prices,dp)+prices[i];
            
            ans=max(ans,sell);

        }
        return dp[i][buying]=ans;

    }
};
