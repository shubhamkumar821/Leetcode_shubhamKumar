class Solution {
public:

   vector<vector<vector<int>>>dp;
   int m,n;
   const int MOD = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        dp.assign(n+1,vector<vector<int>>(m+1,vector<int>(3,-1)));
         return rec(0,0,0,grid)%MOD;
        
        
    }
    int rec(int i,int j,int ch,vector<vector<int>>&grid){

        if(i==n-1 && j==m-1){
            return 1;
        }
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j][ch]!=-1){
            return dp[i][j][ch];
        }
        int ans=0;
        
        if(grid[i][j]==1){
            if(ch==1){
                ans+=rec(i+1,j,2,grid)%MOD;
            }
            else{
               ans+=rec(i,j+1,1,grid)%MOD;
            }
        }
       if(grid[i][j]==0){
        ans+=rec(i,j+1,1,grid)%MOD;
        ans+=rec(i+1,j,2,grid)%MOD;
       }

         
     return dp[i][j][ch]=ans%MOD;

        
    }
};