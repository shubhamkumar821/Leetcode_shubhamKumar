class Solution {
public:
int dp[2590];
vector<int>arr;
int n;
    int lengthOfLIS(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(1+rec(i),ans);
        }
        return ans;
    }


    int rec(int lev){

    int ans=0;
    if(dp[lev]!=-1){
        return dp[lev];
    }

        for(int i=0;i<lev;i++){
            if(arr[lev]>arr[i]){
                ans=max(1+rec(i),ans);
            }
        }

        return dp[lev]=ans;
    }
};