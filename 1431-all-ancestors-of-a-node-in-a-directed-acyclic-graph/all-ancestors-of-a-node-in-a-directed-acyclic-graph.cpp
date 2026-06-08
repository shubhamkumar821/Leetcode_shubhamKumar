class Solution {
public:
vector<vector<int>>g;
vector<vector<int>>ans;

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for(auto i:edges){
            g[i[1]].push_back(i[0]);
        }

        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            vector<int>st;
            dfs(i,vis);
            
            for(int j=0;j<n;j++){
                if(i!=j && vis[j]==1){
                    st.push_back(j);
                }
            }
            ans.push_back(st);

        }
        return ans;
        
    }
    void dfs(int source,vector<int>&vis){
        vis[source]=1;
        for(auto i:g[source]){
            if(!vis[i]){
                dfs(i,vis);
            }
        }
      
    }
};