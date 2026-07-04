class Solution {
public:
   vector<vector<pair<int,int>>>g;
   vector<int>vis;
    int minScore(int n, vector<vector<int>>& roads) {
    int ans=INT_MAX;
        g.resize(n+1);
        vis.assign(n+1,0);
        for(auto i:roads){
            g[i[0]].push_back({i[1],i[2]});
              g[i[1]].push_back({i[0],i[2]});
            
        }
    dfs(1);
        for(auto i:roads){
            int a=i[0];
            int b=i[1];
            int c=i[2];
            if(vis[a] && vis[b] ){
                ans=min(ans,c);
            }

            
        }
        return ans;
    
        
    }

    void dfs(int node){
        vis[node]=1;
        for(auto i:g[node]){
            if(!vis[i.first]){
                dfs(i.first);
            }
        }

    }
};