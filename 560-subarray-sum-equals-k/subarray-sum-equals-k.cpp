class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;

        for(auto i:nums){
            sum+=i;
            cnt+=mp[sum-k];
            mp[sum]++;

        }
        return cnt;
        
    }
};