class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<pair<int,pair<int,int>>>p;
        for(auto i:points){
            int val=(pow(i[0],2)+pow(i[1],2));
            p.insert({val,{i[0],i[1]}});
        }


vector<vector<int>> ans;
int cnt=0;
for(auto i:  p){
    cnt++;
    if(cnt<=k){
        ans.push_back({i.second.first,i.second.second});


    }
    else {
        break;
    }
}

return ans;
    
        
    }
};
