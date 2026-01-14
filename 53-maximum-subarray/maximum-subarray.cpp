class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last=-1e9;
        int ans=-1e9;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                last=nums[i];
            }
            else{
                last=max(last+nums[i],nums[i]);
            }
            ans=max(ans,last);
        }
        return ans;
        
    }
};