class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<(1<<nums.size());i++){
            vector<int> subset;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    subset.push_back(nums[j]);
                    
                }
            }
            s.insert(subset);
        }
      for(auto a:s){
        ans.push_back(a);
      }
      return ans;
        
    }
};