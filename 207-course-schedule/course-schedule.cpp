class Solution {
public:
vector<vector<int>>g;
vector<int>vis;
bool cycle;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        g.resize(n);
        vis.assign(n,0);

        for(auto i:prerequisites){
            g[i[0]].push_back(i[1]);
        }
      for (int i = 0; i < n; i++) {

            if (vis[i] == 0) {

                dfs(i);
            }
        }

        return !cycle;
        
    }
    void dfs(int sc_node){
        vis[sc_node]=1;
        for(auto i:g[sc_node]){
            if(vis[i]==0){
                dfs(i);
            }
            else if(vis[i]==1){
                cycle=true;
            }
        }
        vis[sc_node]=2;
    }
};