class Solution {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int a=i+dx[k];
                        int b=j+dy[k];
                        if( a<0|| b<0|| a>=m||b>=n ||grid[a][b]==0 ){
                            ans++;
                        }
                    }

                }

            }
        }
        return ans;
        
    }
};