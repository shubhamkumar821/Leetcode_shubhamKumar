class Solution {
public:
vector<int>arr;
vector<vector<int>>dp;

int n;

    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
      
        dp=vector<vector<int>>(nums.size()+1,vector<int>(nums.size()+1,-1));
        arr=nums;
        return rec(0,-1);
        
    }
    int rec(int i,int prev){
        if(i==n){
            return 0;
        }
        
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
       }
       int ans=rec(i+1,prev);
        if(   prev==-1 || arr[prev]<arr[i]){
            ans=max(ans,rec(i+1,i)+1);

        }

        return  dp[i][prev+1]= ans;
    }


};