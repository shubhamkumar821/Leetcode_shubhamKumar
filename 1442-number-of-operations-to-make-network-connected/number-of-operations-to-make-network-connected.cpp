class Solution {
public:
vector<vector<int>>g;
vector<int>vis;


    int makeConnected(int n, vector<vector<int>>& connections) {
        int x=connections.size();

        if(x<n-1){
            return -1;

        }
        g.resize(n+1);
        vis.assign(n+1,0);
        for(auto i:connections){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);

        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp++;
                dfs(i);
            }
        }

        return comp-1;

        
    }
    void dfs(int node){
        vis[node]=1;
        for(auto i: g[node]){
            if(!vis[i]){
                dfs(i);
            }
        }

    }
};