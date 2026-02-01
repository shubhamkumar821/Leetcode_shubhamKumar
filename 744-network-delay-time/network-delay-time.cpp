class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> g(n + 1);
        for (auto &i : times) {
            g[i[0]].push_back({i[1], i[2]});
        }

        vector<int> dis(n + 1, 1e9);
        dis[k] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // stale state check
            if (d > dis[u]) continue;

            for (auto &e : g[u]) {
                int v = e.first;
                int w = e.second;

                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == 1e9) return -1;
            ans = max(ans, dis[i]);
        }

        return ans;
    }
};
