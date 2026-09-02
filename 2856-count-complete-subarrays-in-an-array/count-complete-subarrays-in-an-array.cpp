class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int>mp;
        int cnt=0;
        for(auto i:nums){
            if(mp[i]==0){
                cnt++;
            }
            mp[i]++;

        }

        return atmost(nums,cnt)-atmost(nums,cnt-1);
        
    }

    int atmost(vector<int>&nums,int k){
        map<int,int>mp;
        int head=0;
        int cnt=0;
        int ans=0;

        for(int tail=0;tail<nums.size();tail++){

            while(head<nums.size() && (cnt<k || (cnt==k && mp[nums[head]]))){
                if(mp[nums[head]]==0){
                    cnt++;
                }
                mp[nums[head]]++;
                head++;
            }

            ans+=head-tail+1;

            if(mp[nums[tail]]==1){
                cnt--;
            }
            mp[nums[tail]]--;


        }
        return ans;

    }
};