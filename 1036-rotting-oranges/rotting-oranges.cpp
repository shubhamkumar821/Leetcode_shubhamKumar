class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

       queue< pair<int,int>> q;
        int fresh=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                q.push({i,j});
            }
            else if(grid[i][j]==1){
                fresh++;
            }
            }
        }
        if(fresh==0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int min =-1;
       return  bfs(q,grid,dx,dy,fresh ,m,n,min);
    
        
    }
    bool check(int x,int y,int m,int n,vector<vector<int>>& grid){
        if(x>=m || y>=n ||x<0 || y<0 ||  grid[x][y]==0)
        return false;
        else 
         return true;
    }
    int bfs(queue<pair<int,int>> q,vector<vector<int>>&grid,int dx[],int dy[],int fresh,int m,int n,int min){

        while(!q.empty()){
            int size=q.size();
            while(size--){

            pair<int,int> front=q.front();
            q.pop();
        
            for(int i=0;i<4;i++){
                int o=front.first+dx[i];
                int p=front.second+dy[i];

                if(check(o,p,m,n,grid) && grid[o][p]==1){
                    grid[o][p]=2;
                    fresh--;
                    q.push({o,p});

                }
            }
        }
        min++;
        }
        if(fresh==0){
            return min;
        }
        return -1;


    }
};