class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));

       priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> q;
        q.push({grid[0][0],{0,0}});
        dis[0][0]=grid[0][0];
        while(!q.empty()){
            auto [t, p] = q.top();
auto [x, y] = p;
            q.pop();
            if(x==n-1 && y==m-1)return t;

            for(int i=0;i<4;i++){
                int a=x+dx[i];
                int b=y+dy[i];
                if(a>=n || b>=m || a<0 || b<0)continue;
           int time=max(dis[x][y],grid[a][b]);

            if(time < dis[a][b]){
        dis[a][b] = time;
        q.push({time, {a,b}});
         }



            }


        }
        return -1;

        
    }
};