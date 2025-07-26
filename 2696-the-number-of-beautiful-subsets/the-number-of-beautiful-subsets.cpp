class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        map<int,int>mp;
        return rec(0,nums,k,mp)-1;
        
    }
    int rec(int i,vector<int>& nums, int k,map<int,int>&mp){
        if(i==nums.size()){
            return 1;
        }
        int ans=rec(i+1,nums,k,mp);
        if(!mp[nums[i]-k]&& !mp[nums[i]+k] ){
            mp[nums[i]]++;
            ans+=rec(i+1,nums,k,mp);
            mp[nums[i]]--;
        }
        return ans;

    }
};