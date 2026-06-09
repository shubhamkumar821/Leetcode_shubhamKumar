class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int  maxi=INT_MIN;
        int mini=INT_MAX;
        for(auto i:nums){
            maxi=max(maxi,i);
            mini=min(mini,i);
        }
        long long ans=maxi-mini;
        ans*=k;
        return ans;

    }

    
};