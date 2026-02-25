class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
         priority_queue<pair<int,int>>pq;
         for(auto i:arr){
            int x=__builtin_popcount(i);
            pq.push({x,i});

         }
         vector<int>ans;
         while(!pq.empty()){
            int x=pq.top().second;
            ans.push_back(x);
            pq.pop();
         }
         reverse(ans.begin(),ans.end());
         return ans;
        
    }
};