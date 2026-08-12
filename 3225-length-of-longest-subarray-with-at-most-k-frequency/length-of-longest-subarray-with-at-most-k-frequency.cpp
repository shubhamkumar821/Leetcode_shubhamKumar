class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int head=-1;
        int tail=0;
        map<int,int>mp;
        int n=nums.size();
        int ans=0;
        while(tail<n ){
            while(head+1<n && mp[nums[head+1]]<k){
                mp[nums[head+1]]++;
                head++;
            }
            ans=max(ans,head-tail+1);
            mp[nums[tail]]--;
            tail++;
        }
        return ans;
        
    }
};