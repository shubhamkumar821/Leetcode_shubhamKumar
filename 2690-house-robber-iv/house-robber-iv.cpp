class Solution {
public:
    int minCapability(vector<int>& nums, int k) {

        int l=INT_MAX;
        int h=INT_MIN;
        for(auto i:nums){
            l=min(i,l);
            h=max(h,i);
        }
            int ans=h;
        while(l<h){
            long long mid=(l+h)/2;
            if(check(mid,nums,k)){
                h=mid;
                ans=mid;
            }
            else {
               l= mid+1;
            }
        }
        return ans;
        
    }

    bool check(int x,vector<int>& nums,int k){

        int stoled=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<=x){
                stoled++;
                i++;

            }
        }

        return stoled>=k;
    }
};