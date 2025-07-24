class Solution {
public:
vector<vector<int>>dp;
    int uniquePaths(int m, int n) {
    
        dp.resize(m,vector<int>(n,-1));
        return rec(m,n,0,0,0);
        
    }
    int rec(int m,int n,int i,int j,int ans){
        //valid condition 
        if(i>=m || j>=n){
            return 0;
        }
        // base case 
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        ans+=rec(m,n,i+1,j,ans)+rec(m,n,i,j+1,ans);
        dp[i][j]=ans;
        return ans;

    }
};