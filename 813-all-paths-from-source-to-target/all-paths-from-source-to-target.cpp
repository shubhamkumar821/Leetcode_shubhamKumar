class Solution {
public:
vector<vector<int>>ans;
vector<int>vis;
vector<int>num;
int n;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vis.assign(n,0);
        dfs(0,graph);
        return ans;
    
        
    }
    void dfs(int node,vector<vector<int>>& graph){
        
        num.push_back(node);
        if(node==n-1){
            ans.push_back(num);
              num.pop_back();
            return;
        }
        for(auto i:graph[node]){
        
                dfs(i,graph);
            
        }
      num.pop_back();
    
    }
};