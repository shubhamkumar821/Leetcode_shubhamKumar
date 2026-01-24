class Solution {
public:
vector<int>dp;
    int coinChange(vector<int>& coins, int amount) {
        dp=vector<int>(amount+1,-1);
        int ans=rec(amount ,coins);
        if(ans==1e9){
            return -1;
        }
        return ans;

        
    }
    int rec(int sum,vector<int>& coins){
        if(sum==0){
            return 0;
        }
        if(sum<0){
            return 1e9;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int ans=1e9;
        for(auto i:coins){
            ans=min(ans,1+rec(sum-i,coins));
        }
        return dp[sum]=ans;
    }
};