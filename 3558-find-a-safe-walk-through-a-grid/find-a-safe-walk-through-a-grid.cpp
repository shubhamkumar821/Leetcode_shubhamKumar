class Solution {
public:
   vector<vector<int>>dis;
   int dx[4]={1,-1,0,0};
   int dy[4]={0,0,-1,1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        deque<pair<int,int>>dq;
        dq.push_front({0,0});
        dis.assign(n,vector<int>(m,1e9));
        dis[0][0]=grid[0][0];
        while(!dq.empty()){
            auto [x,y]=dq.front();
            dq.pop_front();
            for(int i=0;i<4;i++){

                int a=dx[i]+x;
                int b=dy[i]+y;
                if(a>=n || a<0 || b>=m || b<0 )continue;
                int wt=grid[a][b];

                if(dis[a][b]>dis[x][y]+wt){

                    dis[a][b]=dis[x][y]+wt;
                    if(wt==0){
                       dq.push_front({a,b});

                    }
                    else{
                        dq.push_back({a,b});
                    }
                }
            }
        }

        return dis[n-1][m-1]<health;
        
    }
};