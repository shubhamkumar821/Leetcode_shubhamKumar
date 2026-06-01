class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n=graph.size();
        vector<int>outdeg(n,0),is_safe(n,0);
        vector<vector<int>>vec(n);

        queue<int>q;
        for(int i=0;i<n;i++){
            outdeg[i]=graph[i].size();
            for(auto v:graph[i]){
                vec[v].push_back(i);
            
            }
            if(graph[i].size()==0){
                q.push(i);
            }
            
        }

        while(!q.empty()){
            auto x=q.front();
            q.pop();
            is_safe[x]=1;
            for(auto i:vec[x]){
                outdeg[i]--;
                if(outdeg[i]==0){
                    q.push(i);
                }
                
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(is_safe[i]==1)ans.push_back(i);
        }
        return ans;
        
    }
};