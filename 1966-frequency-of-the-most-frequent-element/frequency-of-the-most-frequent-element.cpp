class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long running_cnt=0;
        int maxi=1;
        int start=0;
        int end=0;
        while(end<nums.size()){
            long long temp=1LL*nums[end]*(end-start);
            long long req=temp-running_cnt;
            if(req<=k){
                maxi=max(maxi,end-start+1);
                running_cnt+=nums[end];
                end++;
            }
            else{
                running_cnt-=nums[start];
                start++;
            }

            if(start>end){
                end=start+1;
            }
        }
        return maxi;
    }
};