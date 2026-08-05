class Solution {
public:
vector<vector<int>>g;
vector<int>vis;
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        g.resize(n);
        vis.assign(n,0);
        int m=invocations.size();
        for(auto  i:invocations){
            int a=i[0];
            int b=i[1];
            g[a].push_back(b);
        }
        queue<int>q;
        q.push(k);
        vis[k]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto i:g[x]){
                if(!vis[i]){
                vis[i]=1;
                q.push(i);
                }
            }
        }
      for(auto &e:invocations){
            if(!vis[e[0]] && vis[e[1]]){
                vector<int>ans;
                for(int i=0;i<n;i++)ans.push_back(i);
                return ans;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)if(!vis[i]) ans.push_back(i);
        return ans;
        
    }
};