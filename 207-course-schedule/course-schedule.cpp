class Solution {
public:
vector<vector<int>>g;
vector<int>vis;
bool cycle_detected=false;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        g.resize(n);
        vis.assign(n,0);
        for(auto i:prerequisites){
            g[i[1]].push_back(i[0]);
        }
       for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
       }
       return !cycle_detected;
        
        
    }

    void dfs(int node){
        vis[node]=1;
        for(auto i:g[node]){
            if(vis[i]==0){
                dfs(i);
            }
            else if(vis[i]==1 && cycle_detected==false)
            {
                cycle_detected=true;
            }
            
        }
        vis[node]=2;

    }
};
