class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>> ans;
        return solve(0,candidates,target,ds,ans);
        

        
    }
vector<vector<int>> solve(int ind,vector<int>& candidates, int target,vector<int>& ds,vector<vector<int>>& ans){
    
    if(ind==candidates.size()){
if(target==0){
    ans.push_back(ds);
}
return ans;
    }
    if(candidates[ind]<=target){
        ds.push_back(candidates[ind]);
        solve(ind,candidates,target-candidates[ind],ds,ans);
        ds.pop_back();

    }
    solve(ind +1,candidates,target,ds,ans);
    return ans;
}
};