class Solution {
public:
vector<vector<int>>g;
int n;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         n=numCourses;
        vector<int> outdeg(n, 0);

        g.resize(n);

        // Build directed graph
        for(auto i : prerequisites) {
            g[i[0]].push_back(i[1]);
            outdeg[i[0]]++;
              g[i[1]].push_back(i[0]);
        }

        queue<int> q;

        // Nodes with out-degree 0
        for(int i = 0; i < n; i++) {
            if(outdeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> v;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            v.push_back(node);

            // Remove node from its predecessors
            for(auto nei : g[node]) {

                outdeg[nei]--;

                if(outdeg[nei] == 0) {
                    q.push(nei);
                }
            }
        }

       if(v.size()!=n){
           return {};
       }
       return v;
        
    }
};