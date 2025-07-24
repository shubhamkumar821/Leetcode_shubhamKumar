

class Solution {
public:
vector<vector<int>>dp;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        dp.resize(m,vector<int>(n,-1));
        return rec(m,n,0,0,0,obstacleGrid);
        
        
    }
     int rec(int m,int n,int i,int j,int ans,vector<vector<int>>& nums){
        //valid condition 
        if(i>=m || j>=n){
            return 0;
        }
        if(nums[i][j]==1){
        return 0;
        }
    
        // base case 
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        ans+=rec(m,n,i+1,j,ans,nums)+rec(m,n,i,j+1,ans,nums);
        dp[i][j]=ans;
        return ans;

    }
};