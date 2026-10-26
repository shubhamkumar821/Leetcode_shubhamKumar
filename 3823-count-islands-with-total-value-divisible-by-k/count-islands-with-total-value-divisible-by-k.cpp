class Solution {
public:
     vector<vector<int>>vis;
      int m,n;
      int dx[4]={1,-1,0,0};
      int dy[4]={0,0,-1,1};
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
         
         int cnt=0;
         vis.assign(m,vector<int>(n,0));
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    long long sum=0;
                    dfs(i,j,grid,sum);
                    if(sum%k==0){
                        cnt++;
                    }
                }
            }
          }
        
        return cnt;
    }

    void dfs(int x,int y,vector<vector<int>>&grid,long long  &sum){

    

        vis[x][y]=1;
        sum+=grid[x][y];


        for(int i=0;i<4;i++){
            int X=x+dx[i];
            int Y=y+dy[i];
            if(X>=m || Y>=n || X<0 || Y<0 || grid[X][Y]==0)continue;
            if(vis[X][Y]==0){
                dfs(X,Y,grid,sum);
            }

        }



    }
};