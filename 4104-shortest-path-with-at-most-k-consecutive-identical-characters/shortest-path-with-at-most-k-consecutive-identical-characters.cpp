class Solution {
public:
    vector<vector<pair<int,int>>> g;

    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        g.assign(n, {});

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        using T = tuple<int,int,int>;

        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [d, node, cnt] = pq.top();
            pq.pop();

            if (d != dist[node][cnt])
                continue;

            if (node == n - 1)
                return d;

            for (auto [neighbour, weight] : g[node]) {

                int newCnt = (labels[node] == labels[neighbour])
                             ? cnt + 1 : 1;

                if (newCnt > k)
                    continue;

                int newDist = d + weight;

                if (newDist < dist[neighbour][newCnt]) {

                    dist[neighbour][newCnt] = newDist;

                    pq.push({newDist, neighbour, newCnt});
                }
            }
        }

        return -1;
    }
};