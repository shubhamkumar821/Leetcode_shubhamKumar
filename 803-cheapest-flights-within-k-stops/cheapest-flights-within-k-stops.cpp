class Solution {
public:
    vector<vector<pair<int,int>>> g;
    vector<vector<int>> dis;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        g.resize(n);
        dis.assign(n, vector<int>(k + 2, 1e9));

        for(auto &i : flights){
            g[i[0]].push_back({i[1], i[2]});
        }

        return dijk(src, dst, k);
    }

    int dijk(int sc, int dst, int k) {
        dis[sc][0] = 0;

        // cost, node, stops
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        pq.push({0, sc, 0});

        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int cost  = cur[0];
            int node  = cur[1];
            int stops = cur[2];

            if(node == dst) return cost;
            if(stops > k) continue;

            for(auto &i : g[node]) {
                int nei = i.first;
                int wt  = i.second;

                if(dis[nei][stops + 1] > cost + wt) {
                    dis[nei][stops + 1] = cost + wt;
                    pq.push({cost + wt, nei, stops + 1});
                }
            }
        }
        return -1;
    }
};
