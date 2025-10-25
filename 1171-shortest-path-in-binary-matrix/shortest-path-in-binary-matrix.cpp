class Solution {
public:
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,1,1,-1,-1};
int n;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        n=grid.size();
        vector<vector<int>>dis(n,vector<int>(n,1e9));

        bfs({0,0},grid,dis);
        if(dis[n-1][n-1]==1e9){
            return -1;
        }
        return dis[n-1][n-1];

        
    }
    void bfs(pair<int,int>p,vector<vector<int>>& grid, vector<vector<int>>&dis){
        queue<pair<int,int>>q;
        q.push(p);
        dis[0][0]=1;

        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int a=x.first+dx[i];
                int b=x.second+dy[i];
                if(check(a,b,grid)){
                    if(dis[a][b]>dis[x.first][x.second]+1){
                        dis[a][b]=dis[x.first][x.second]+1;
                        q.push({a,b});
                    }
                }
            }

        }

        
    }
    bool check(int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=n ||j<0||j>=n||grid[i][j]==1){
            return false ;
        }
        return true;

    }
};