class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>g;
        g.resize(n);

        for(auto i:flights)g[i[0]].push_back({i[1],i[2]});
          queue<pair<int,pair<int,int>>>pq;

             vector<int> dis(n, 1e9);
             dis[src] = 0; 
                  
                  pq.push({0,{src,0}});

                  while(!pq.empty()){
                    auto x=pq.front();
                    pq.pop();
                    int a=x.first;
                    int b=x.second.first;
                   int c= x.second.second;
                    if(a>k)
                    {
                        continue;
                    }

                    for(auto i:g[b]){
                      int wt=i.second;
                      int node=i.first;

                      if(c+wt<dis[node] && a<=k){
                        dis[node]=c+wt;
                        pq.push({a+1,{node,c+wt}});
                      }
                    }

                  }

                  if(dis[dst]!=1e9){
                    return dis[dst];
                  }

    return -1;

                                     
        
    }
};