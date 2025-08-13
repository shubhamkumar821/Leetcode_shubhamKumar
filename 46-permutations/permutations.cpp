class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {  map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector<int>ans;
        set<vector<int>>st;
        rec(0,mp,nums,ans,st);
        vector<vector<int>> myans;

        for(auto i:st){
      myans.push_back(i);

        }
        return myans;
        
        
    }

    void rec(int lev,map<int,int> mp,vector<int>&nums,vector<int>&ans,set<vector<int>>&store){
    if(lev==nums.size()){
        store.insert(ans);
    }

    for(auto i : mp){
        if(i.second){
            ans.push_back(i.first);
            mp[i.first]--;
            rec(lev+1,mp,nums,ans,store);
           
            mp[i.first]++;
             ans.pop_back();

        }
    }

}
};