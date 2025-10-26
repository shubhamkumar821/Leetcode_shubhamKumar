class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int>no_ways(n,0);
        vector<long long >dis(n,LLONG_MAX);
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            long long wt=it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});

        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>pq;
           pq.push({0, 0});
        dis[0] = 0;
        no_ways[0] = 1;
        int mod = 1e9 + 7;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            long long dt=it.first;
            if(dt>dis[node])
            continue;
            for(auto i:adj[node]){
                int adjnode=i.first;
                long long wt=i.second;
                if(dis[adjnode]>(dt+wt)){

                    dis[adjnode]=(dt+wt);
                    no_ways[adjnode]=(no_ways[node]);
                    pq.push({dis[adjnode],adjnode});
                }

                else if(dis[adjnode]==dt+wt){
                    no_ways[adjnode]=(no_ways[node]+no_ways[adjnode])%mod;
                }
            }
        }
        return no_ways[n-1]%mod;
        
    }
};