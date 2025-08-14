class Solution {
    int m,n;
    vector<vector<int>>dis;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        dis=vector<vector<int>>(m,vector<int>(n,1e9));
        return dijkstra(heights);

        

        
        
     
}
int  dijkstra(vector<vector<int>>& heights){
     priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        minHeap.push({0, 0, 0}); // {diff, row, col}

    dis[0][0]=0;
    while(!minHeap.empty()){
        auto x=minHeap.top();
        minHeap.pop();
        int diff=x[0];
        int r=x[1];
        int c=x[2];
        if(r==m-1 && c==n-1)
        return diff;
    for(int i=0;i<4;i++){
        int a=r+dx[i];
        int b=c+dy[i];
        if(check(a,b)){

            int newdiff=max(diff,abs(heights[a][b]-heights[r][c]));
            if(newdiff<dis[a][b]){
                dis[a][b]=newdiff;
                minHeap.push({newdiff,a,b});
            }


            }
        }

    }
    return 0;

    }

bool check(int x,int y){
    if(x<0 || x>=m || y<0 || y>=n)
    return 0;
    return 1;
}}

;