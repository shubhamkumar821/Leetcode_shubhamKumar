class Solution {
public:
int m, n, K;
    const int MOD = 1000000007;
    vector<vector<vector<int>>> dp;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
       K=k;
        dp.assign(n,vector<vector<int>>(m,vector<int>(k,-1)));

        return rec(0,0,0,grid);
        
    }

    int rec(int i,int j,int sum,vector<vector<int>>& grid){
 if(i>=n || j>=m){
            return 0;
        }
        sum=(sum+grid[i][j])%K;
        if(i==n-1 && j==m-1){
            if(sum%K==0){
                return 1;
            }
            return 0;
        }

       
        if(dp[i][j][sum]!=-1){
            return dp[i][j][sum];
        }

        
          int ans=0;
     ans+=(rec(i+1,j,sum,grid)+rec(i,j+1,sum,grid)) %MOD;

         return dp[i][j][sum]=ans%MOD;

    }
};