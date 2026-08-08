class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }

        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]-1] ||mp[nums[i]+1]||mp[nums[i]]>1)continue;
            ans.push_back(nums[i]);

        }
        return ans;
        
    }
};