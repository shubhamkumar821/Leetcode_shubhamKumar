class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i:nums){
            mpp[i]++;
        }
        vector<int>ans;
        for(auto i:mpp){
            if(i.second>n/3){
                ans.push_back(i.first);
            }
        }
        return ans;
        
    }
};