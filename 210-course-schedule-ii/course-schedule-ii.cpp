class Solution {
public:
vector<vector<int>>g;
vector<int>vis;
bool cycle;
vector<int>ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n=numCourses;
        g.resize(n);
        vis.assign(n,0);
        vector<int>st;

        for(auto i:prerequisites){
            g[i[0]].push_back(i[1]);
        }
      for (int i = 0; i < n; i++) {

            if (vis[i] == 0) {

                dfs(i);
            }
        }
        if(!cycle){
            return ans;
        }
return st ;
        
    }
    void dfs(int node){
         vis[node]=1;
        for(auto i:g[node]){
            if(vis[i]==0){
                dfs(i);
            }
            else if(vis[i]==1){
                cycle=true;
            }
        }
        vis[node]=2;
        ans.push_back(node);

    }
};