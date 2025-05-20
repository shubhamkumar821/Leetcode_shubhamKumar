class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        vector<pair<int,int>> p;
        for(auto i: mp){
            p.push_back({i.second,i.first});
        }
        sort(p.rbegin(),p.rend());
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(p[i].second);
        }
        return ans;
        
    }
};