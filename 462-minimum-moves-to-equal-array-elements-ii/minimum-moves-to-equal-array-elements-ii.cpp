class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n&1){
            int med=nums[n/2];
            int ans=0;

            for(auto i:nums){
                ans+=abs(i-med);
            }
            return ans;
        }

        else{


              int med=nums[n/2]+nums[n/2 -1];
              med=med/2;
            int ans=0;

            for(auto i:nums){
                ans+=abs(i-med);
            }
            return ans;
        }
        return 1;
        
    }
};