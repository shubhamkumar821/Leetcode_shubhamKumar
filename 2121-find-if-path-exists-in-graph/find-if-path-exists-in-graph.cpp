class Solution {
public:
vector<vector<int>>g;
vector<int>vis;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        g.resize(n);
        vis.assign(n,0);
        for(auto i:edges){
            g[i[0]].push_back(i[1]);
             g[i[1]].push_back(i[0]);
        }
        dfs(source);

        return vis[destination];
        
    }
    void dfs(int node){
        vis[node]=1;
        for(auto i:g[node]){
            if(vis[i]==0){
                dfs(i);
            }
        }
    }
};