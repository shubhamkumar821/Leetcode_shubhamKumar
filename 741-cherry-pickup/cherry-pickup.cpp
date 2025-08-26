class Solution {
public:
    int dx[2]={0,1};
    int dy[2]={1,0};
    int n,m;
    int dp[60][60][60][60];

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,0,0,0,grid);
        return max(0, ans); // if no valid path, return 0
    }

    int rec(int i,int j,int a,int b ,vector<vector<int>>& grid)
    {
        // invalid states
        if(!check(i,j,grid) || !check(a,b,grid)) return -1000000000;

        // base case: both reach end
        if(i==n-1 && j==m-1 && a==n-1 && b==m-1) {
            return grid[i][j];
        }

        if(dp[i][j][a][b]!=-1) return dp[i][j][a][b];

        int cost = grid[i][j];
        if(i!=a || j!=b) cost += grid[a][b]; // avoid double counting

        int ans = -1000000000;
        for(int k1=0;k1<2;k1++){
            for(int k2=0;k2<2;k2++){
                int ni=i+dx[k1];
                int nj=j+dy[k1];
                int na=a+dx[k2];
                int nb=b+dy[k2];
                int next = rec(ni,nj,na,nb,grid);
                if(next > -1000000000) {
                    ans = max(ans, cost + next);
                }
            }
        }
        return dp[i][j][a][b] = ans;
    }

    bool check(int a,int b,vector<vector<int>>& grid){
        if(a<0 || a>=n || b<0 || b>=m || grid[a][b]==-1) return false;
        return true;
    }
};
