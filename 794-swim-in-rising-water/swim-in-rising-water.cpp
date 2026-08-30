
class Solution {
public:

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        // {maximum water level, {row, column}}
        pq.push({grid[0][0], {0, 0}});
        dis[0][0] = grid[0][0];

        while (!pq.empty()) {

            auto x = pq.top();
            pq.pop();

            int cost = x.first;
            int r = x.second.first;
            int c = x.second.second;

            // Destination reached
            if (r == n - 1 && c == m - 1) {
                return cost;
            }

            // Explore 4 directions
            for (int i = 0; i < 4; i++) {

                int a = r + dx[i];
                int b = c + dy[i];

                if (a < 0 || b < 0 || a >= n || b >= m)
                    continue;

                // Water level needed to reach this cell
                int newCost = max(cost, grid[a][b]);

                // Found a better path
                if (newCost < dis[a][b]) {

                    dis[a][b] = newCost;

                    pq.push({newCost, {a, b}});
                }
            }
        }

        return -1;
    }
};

