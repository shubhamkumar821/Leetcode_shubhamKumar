class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<pair<int,int>>>comp;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
              

                if(grid[i][j]==1 && vis[i][j]==0){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j]=1;
                      vector<pair<int,int>>st;
            


                    while(!q.empty()){
                        auto [x,y]=q.front();
                       st.push_back({x,y});

                        q.pop();

                        for(int i=0;i<4;i++){
                            int X=x+dx[i];
                            int Y=y+dy[i];
                            if(X<0 || Y<0 || X>=n || Y>=m || grid[X][Y]==0 || vis[X][Y]==1)continue;

                            if(grid[X][Y]==1 && vis[X][Y]==0){
                                vis[X][Y]=1;
                                q.push({X,Y});

                            }

                        }
                    }
                    comp.push_back(st);
                   

                }

               
            }
        }
        for(auto i:  comp){
            int x=i.size();
            ans=max(x,ans);
        }

        return ans;

        

        
    }
};