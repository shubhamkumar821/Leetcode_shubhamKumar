class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};

    int n,m;
    vector<vector<int>> vis;

    int closedIsland(vector<vector<int>>& grid) {

        n=grid.size();
        m=grid[0].size();

        vis.assign(n,vector<int>(m,0));

        int comp=0;

        for(int a=0;a<n;a++) {

            for(int b=0;b<m;b++) {

                if(grid[a][b]==0 && !vis[a][b]) {

                    queue<pair<int,int>> pq;

                    bool closed=true;

                    pq.push({a,b});
                    vis[a][b]=1;

                    while(!pq.empty()) {

                        auto node=pq.front();
                        pq.pop();

                        int r=node.first;
                        int c=node.second;

                        // current cell touches boundary
                        if(r==0 || c==0 || r==n-1 || c==m-1) {
                            closed=false;
                        }

                        for(int i=0;i<4;i++) {

                            int x=dx[i]+r;
                            int y=dy[i]+c;

                            if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==1) {
                                continue;
                            }

                            if(!vis[x][y]) {

                                vis[x][y]=1;
                                pq.push({x,y});
                            }
                        }
                    }

                    if(closed) {
                        comp++;
                    }
                }
            }
        }

        return comp;
    }
};