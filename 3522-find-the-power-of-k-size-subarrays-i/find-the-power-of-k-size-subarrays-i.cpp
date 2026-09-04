class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        for(int i=0;i<=nums.size()-k;i++){
            if(sorted(nums,i,i+k)){
                ans.push_back(nums[i+k-1]);

            }
            else{
                ans.push_back(-1);
            }

        }
       // ans.pop_back();
        return ans;
        
    }
    bool sorted(vector<int>&nums,int i,int j){

        for(int x=i+1;x<j;x++){
            if(nums[x-1]+1!=nums[x])return false;
        }
        return true;

    }
};