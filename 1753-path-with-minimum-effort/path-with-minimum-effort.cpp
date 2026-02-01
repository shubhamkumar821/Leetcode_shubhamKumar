class Solution {
public:
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m;
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>>g(vector<vector<int>>(heights.size(),vector<int>(heights[0].size(),1e9)));
        n=heights.size();
        m=heights[0].size();
        g[0][0]=0;

       priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;

        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto x=pq.top();
            int a=x.second.first;
            int b=x.second.second;
            int w=x.first;
            pq.pop();
            for(int i=0;i<4;i++){
                int x=a+dx[i];
                int y=b+dy[i];
                if(x<0 || y<0 || y>=m || x>=n){
                    continue;
                }
            
                if(g[x][y]>max(abs(heights[a][b]-heights[x][y]),g[a][b]))

                {
                    g[x][y]=max(abs(heights[a][b]-heights[x][y]),g[a][b]);
                    pq.push({g[x][y],{x,y}});

                }

            }
        }
        return g[n-1][m-1];
        
    }
};