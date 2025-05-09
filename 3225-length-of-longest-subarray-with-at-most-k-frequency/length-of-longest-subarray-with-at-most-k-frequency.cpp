class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int head=-1;
        int tail=0;
        
        int n=nums.size();
        int ans=0;
        map<int ,int> mp;
        while(tail<n){
            while(head+1<n && mp[nums[head+1]]<k){
                head++;
                
                    mp[nums[head]]++;
            }
            ans=max(ans,head-tail+1);

            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                mp[nums[tail]]--;
                tail++;
            }
        }
        return ans;

        
        
    }
};