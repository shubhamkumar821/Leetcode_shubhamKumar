class Solution {
public:
vector<vector<int>> dp;

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        return rec(m,n,grid,0,0,0);
        
    }
   int  rec(int m,int n,vector<vector<int>>& grid,int i,int j,int ans){
    if(i>=m||j>=n){
        return 1e9;
    }
    if(i==m-1 && j==n-1){
        return grid[m-1][n-1];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
     ans=min(grid[i][j]+rec(m,n,grid,i+1,j,0),grid[i][j]+rec(m,n,grid,i,j+1,0));
    dp[i][j]=ans;
    return ans;
    
   }
};