class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dis(m, vector<int>(n, 1e9));

        deque<pair<int,int>> dq;

        dis[0][0] = 0;
        dq.push_front({0,0});

        while(!dq.empty()) {
            auto [x,y] = dq.front();
            dq.pop_front();

            for(int k=0;k<4;k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx<0 || ny<0 || nx>=m || ny>=n)
                    continue;

                int wt = grid[nx][ny];

                if(dis[x][y] + wt < dis[nx][ny]) {
                    dis[nx][ny] = dis[x][y] + wt;

                    if(wt == 0)
                        dq.push_front({nx,ny});
                    else
                        dq.push_back({nx,ny});
                }
            }
        }

        return dis[m-1][n-1];
    }
};