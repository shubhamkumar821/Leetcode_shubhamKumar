class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
       
    }

    int atmost(vector<int>&nums,int k){

          map<int,int>mp;
        int j=0;
        int ans=0;
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            while(j<nums.size() && (cnt<k  || (cnt==k && mp[nums[j]]))){
                if(mp[nums[j]]==0){
                    cnt++;
                }
                mp[nums[j]]++;
                j++;
            }
        
            ans+=j-i;

            if(mp[nums[i]]==1){
                cnt--;
            }
            mp[nums[i]]--;

        
        }
        return ans;

    }
};