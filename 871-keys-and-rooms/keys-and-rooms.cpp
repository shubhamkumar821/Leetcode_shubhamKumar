class Solution {
public:

vector<int>vis;

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
         vis.assign(n,0);
         dfs(0,rooms);
         for(auto i:vis){
            if(i==0)return false;
         }
         return true;
        
    }
    void dfs(int node,vector<vector<int>>& rooms){
        vis[node]=1;
        for(auto i:rooms[node]){
            if(!vis[i]){
                dfs(i,rooms);
            }
        }
    }
};