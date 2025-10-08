class Solution {
public:
//vector<vector<int>>g;
    int findChampion(int n, vector<vector<int>>& edges) {
       // g.resize(n);
        vector<int>indgre(n,0);
        

        for(auto i: edges){
           // g[i[0]].push_back(i[1]);
            indgre[i[1]]++;

        }
        int cnt=0;
        int ans=-1;

      for(int i=0;i<n;i++){
        if(indgre[i]==0){
            cnt++;
            ans=i;

        }
      }

      if(cnt==1){
        return ans;
      }

      else{
        return -1;
      }
        
    }
};