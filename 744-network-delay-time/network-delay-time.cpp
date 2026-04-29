class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>g[n+1];
        for(auto i:times)g[i[0]].push_back({i[1],i[2]});
        queue<pair<int,int>>pq;
        pq.push({k,0});
        vector<int>dis(n+1,1e9);
        dis[k]=0;
        while(!pq.empty()){
            auto x=pq.front();
            pq.pop();

            int src=x.first;
            int wt=x.second;
            for(auto i:g[src]){
                if(wt+i.second<dis[i.first]){
                    dis[i.first]=wt+i.second;
                    pq.push({i.first,wt+i.second});
                }
            }

        }
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9)return -1;
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dis[i]);
        }
        return ans;
        
        
    }
};