class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size() -1;
        if(nums.size()==1){
            return 0;
        }
        if(nums[r]>nums[r-1]){
            return r;
        }

        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]>nums[m+1])
            {
                r=m-1;
                
            }
            else {
                l=m+1;
                
            }
        }
        int ans=l;
        return l;
        
    }
};