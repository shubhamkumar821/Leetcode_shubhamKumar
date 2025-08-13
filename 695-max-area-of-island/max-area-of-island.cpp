class Solution {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    vector<vector<int>>vis;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       vis= vector<vector<int>>(m,vector<int>(n,0));

        vector<int> size_of_comp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]  && grid[i][j] == 1){
                    int cnt=0;
                    dfs({i,j},cnt,m,n,grid);
                    size_of_comp.push_back(cnt);
                }
            }
        }
        int ans=0;
        for(auto i: size_of_comp){
            ans=max(ans,i);
        }
        return ans;
        
        
    }
    void dfs(pair<int,int> st,int& cnt,int m,int n,vector<vector<int>>&grid){
        vis[st.first][st.second]=1;
        cnt++;
        for(int i=0;i<4;i++){
            int x=st.first+dx[i];
            int y=st.second+dy[i];
            if(check(x,y,m,n,grid)){
                if(!vis[x][y]){
                    
                    dfs({x,y},cnt,m,n,grid);


                }
            }
        }

    }
    bool check(int x,int y,int m,int n,vector<vector<int>>&grid){
           if(x<0 || y<0|| y>=n|| x>=m || grid[x][y]==0){
            return 0;
        }
        return 1;



    }
};
