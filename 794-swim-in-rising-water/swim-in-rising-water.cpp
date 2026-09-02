
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

       
        pq.push({grid[0][0], {0, 0}});
        dis[0][0] = grid[0][0];

        while (!pq.empty()) {

            auto x = pq.top();
            pq.pop();

            int cost = x.first;
            int r = x.second.first;
            int c = x.second.second;

      
            if (r == n - 1 && c == m - 1) {
                return dis[r][c];
            }

            
            for (int i = 0; i < 4; i++) {

                int a = r + dx[i];
                int b = c + dy[i];

                if (a < 0 || b < 0 || a >= n || b >= m)
                    continue;

             
                int newCost = max(cost, grid[a][b]);

              
                if (newCost < dis[a][b]) {

                    dis[a][b] = newCost;

                    pq.push({newCost, {a, b}});
                }
            }
        }

        return -1;
    }
};

