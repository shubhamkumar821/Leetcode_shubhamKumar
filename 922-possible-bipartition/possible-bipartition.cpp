class Solution {
public:
vector<int>vis;
vector<vector<int>>g;
bool check=true;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        g.resize(n+1);
        vis.assign(n+1,0);
        for(auto i:dislikes){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        for(int i=1;i<=n;i++){
            if(!vis[i])dfs(i,2);
        }
     
        return check;
        
    }
    void dfs(int node ,int color){
        vis[node]=color;
        for(auto i:g[node]){
            if(vis[i]==0){
                dfs(i,3-color);
            }
            else if(vis[node]==vis[i]){
                check=false;
            }
        }
    }
};