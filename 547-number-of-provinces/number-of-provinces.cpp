class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
int n=isConnected.size();
        vector<int>vis(n,0);
    
        int cnt=0;
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    ans[i].push_back(j);

                }
            }
        }  

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(ans,vis,i);

            }

        }
        return cnt;
        
    }
    void dfs(vector<vector<int>>& ans ,vector<int>& vis,int node){
        vis[node]=1;
        for(auto i: ans[node]){
            if(!vis[i]){
                dfs(ans,vis,i);
            }
        }

    }
};