class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if(nums.size()==1){
            return nums[0];
        }
        int ans=0;
        for(int i=0;i<32;i++){
            long long sum=0;
            for(int j=0;j<nums.size();j++){
                sum+=(nums[j]&(1<<i));

            }
            if(sum%3){
                ans|=(1<<i);
            }

        }
        return ans;
    }
};