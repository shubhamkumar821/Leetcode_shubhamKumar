class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
      int res=0;
        for( int i=0;i<(1<<nums.size());i++){
             int ans=0;
            for(int j =0;j<nums.size();j++){ 

                if((i>>j)&1){
                    ans^=nums[j];

                }
            }
            res+=ans;
        
        }
        return res;
    }
};