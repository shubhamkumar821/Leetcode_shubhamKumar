class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Distance matrix
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // Min-heap: {cost, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        // Start from (0,0)
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int dr[2] = {0, 1}; // right, down
        int dc[2] = {1, 0};

        while (!pq.empty()) {
            auto [cost, cell] = pq.top();
            pq.pop();

            int r = cell.first;
            int c = cell.second;

            // Early exit if reached destination
            if (r == m - 1 && c == n - 1)
                return cost;

            if (cost > dist[r][c]) continue;

            for (int k = 0; k < 2; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < m && nc < n) {
                    int newCost = cost + grid[nr][nc];

                    if (newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, {nr, nc}});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};
