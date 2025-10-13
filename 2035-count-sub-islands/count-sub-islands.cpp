class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    // do BFS from (i, j)
                    if (isSubIsland(i, j, grid1, grid2))
                        ans++;
                }
            }
        }
        return ans;
    }
    
    bool isSubIsland(int si, int sj,
                      vector<vector<int>>& grid1,
                      vector<vector<int>>& grid2) {
        queue<pair<int,int>> q;
        q.push({si, sj});
        // Mark visited in grid2
        grid2[si][sj] = 0;
        
        bool isSub = true;  // assume this island is a sub-island until proven otherwise
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // If this cell is water in grid1, then this island cannot be a sub-island
            if (grid1[x][y] == 0) {
                isSub = false;
            }
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (grid2[nx][ny] != 1) continue;
                
                // Visit it
                grid2[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
        
        return isSub;
    }
};
