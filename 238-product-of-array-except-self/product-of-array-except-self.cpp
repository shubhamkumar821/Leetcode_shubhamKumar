class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int cnt0=0;
        int n=nums.size();
        for(auto i:nums)
        {
            if(i!=0)
            {
                prod=prod*i;
            }
            else
            {
            cnt0++;
            }

        }
        if(cnt0>1)
        {
           vector<int>ans(n,0);
           return ans;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(cnt0==1)
            {
              if(nums[i]!=0){
                ans[i]=0;
              }
              else{
                ans[i]=prod;
              }
            }
            else
            {
             ans[i]=prod/nums[i];
     
            }
        }
        return ans;
    }
};