class Solution {
public:
vector<vector<int>>g;
vector<int>vis;
const int mod=1e9+7;
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        g.resize(n+2);
        vis.assign(n+2,0);
        for(auto i:edges){
            g[i[0]].push_back(i[1]);
             g[i[1]].push_back(i[0]);
        }
        int ans=dfs(1);
      int fans=1;
        for(int i=1;i<=ans-1;i++){
            fans*=2;
            fans=fans%mod;

        }
        return fans;

        
    }
    int dfs(int node){
        vis[node]=1;
        int ans=0;
        for(auto i:g[node]){
            if(!vis[i]){
                ans=max(1+dfs(i),ans);
            }

        }
        return ans;
    }
};