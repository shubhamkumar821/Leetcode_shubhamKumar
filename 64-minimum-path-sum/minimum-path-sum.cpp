class Solution {
public:
vector<vector<int>>dp;
int n,m;
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n+1,vector<int>(m+1,-1));
       return rec(0,0,grid);

        
    }
    int rec(int i,int j,vector<vector<int>>& grid){
        if(i==n-1 && j==m-1)return grid[i][j];
        if(i>=n || j>=m) return 1e5;
        if(dp[i][j]!=-1)return dp[i][j];

        int ans=INT_MAX;
        ans=min({ans,rec(i+1,j,grid)+grid[i][j],rec(i,j+1,grid)+grid[i][j]});
        return dp[i][j]=ans;
    }
};