class Solution {
public:
int n,f;
vector<vector<int>>dp;
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        f=fee;
        dp.assign(n+1,vector<int>(2,-1));
        return rec(0,0,prices);
        
    }

    int rec(int i,int state,vector<int>&prices){

        if(i==n)return 0;
        if(dp[i][state]!=-1)return dp[i][state];
        int ans=0;

        if(state==0){
            int buy=rec(i+1,1,prices)-prices[i];
            int nbuy=rec(i+1,0,prices);
            ans=max(buy,nbuy);
        }

         else{int sell=rec(i+1,0,prices)+prices[i]-f;
        int dsell=rec(i+1,1,prices);
        ans=max(sell,dsell);
         }
        return dp[i][state]= ans;
    }
};