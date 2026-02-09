class Solution {
public:
vector<int>nums;
int dp[1001];
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        nums=arr;
        memset(dp,-1,sizeof(dp));

        return rec(0,k);
        
    }
    int rec(int i,int k){
        if(i>=nums.size())return 0;
          int maxi=INT_MIN;
          int sum=INT_MIN;
          if(dp[i]!=-1){
            return dp[i];
          }

        for(int j=i;j< min(i+k,int(nums.size()));j++){
            maxi=max(maxi,nums[j]);

            sum=max(sum,rec(j+1,k)+maxi*(j+1-i));

        }
        return dp[i]=sum;

    }
};