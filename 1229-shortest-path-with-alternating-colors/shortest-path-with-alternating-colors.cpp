class Solution {
public:

    vector<vector<pair<int,int>>> g;

    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& R,
        vector<vector<int>>& B) {

        g.resize(n);

        // 0 = red
        // 1 = blue

        for(auto &i : R) {
            g[i[0]].push_back({i[1],0});
        }

        for(auto &i : B) {
            g[i[0]].push_back({i[1],1});
        }

        vector<vector<int>> dist(n, vector<int>(2,1e9));

        queue<pair<int,int>> q;

        // start from node 0 with both colors

        dist[0][0] = 0;
        dist[0][1] = 0;

        q.push({0,0});
        q.push({0,1});

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            int u = node.first;
            int prevColor = node.second;

            for(auto &i : g[u]) {

                int v = i.first;
                int edgeColor = i.second;

                // alternating color
                if(edgeColor != prevColor) {

                    if(dist[v][edgeColor] > dist[u][prevColor] + 1) {

                        dist[v][edgeColor] =
                            dist[u][prevColor] + 1;

                        q.push({v, edgeColor});
                    }
                }
            }
        }

        vector<int> ans;

        for(int i=0;i<n;i++) {

            int x = min(dist[i][0], dist[i][1]);

            if(x == 1e9) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(x);
            }
        }

        return ans;
    }
};