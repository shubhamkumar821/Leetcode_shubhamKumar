class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        vector<vector<pair<int,double>>> g(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            g[u].push_back({v, succProb[i]});
            g[v].push_back({u, succProb[i]});
        }

        vector<double> dis(n, 0.0);

        priority_queue<pair<double,int>> pq;

        dis[start_node] = 1.0;
        pq.push({1.0, start_node});

        while(!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if(prob < dis[node]) continue;

            if(node == end_node) return prob;

            for(auto &[neigh, weight] : g[node]) {
                if(dis[node] * weight > dis[neigh]) {
                    dis[neigh] = dis[node] * weight;
                    pq.push({dis[neigh], neigh});
                }
            }
        }

        return 0.0;
    }
};