class Solution {
public:
int dice,tar,fd;
vector<vector<int>>dp;
#define MOD 1000000007
    int numRollsToTarget(int n, int k, int target) {
        dice=n;
        tar=target;
        fd=k;

        dp.assign(target+1,vector<int>(n+1,-1));

        int ans=rec(0,0);
        return ans;

        
    }
    int rec(int sum,int step){

        if(sum==tar && step==dice){
            return 1;
            
        }
        if(step>dice){
            return 0;
        }
        if(sum>tar){
            return 0;
        }
        if(dp[sum][step]!=-1){
            return dp[sum][step]%MOD;
        }
        long long ans=0;

        for(int i=1;i<=fd;i++){
            ans+=rec(sum+i,step+1)%MOD;
        }
        return dp[sum][step]=ans%MOD;

    }
};