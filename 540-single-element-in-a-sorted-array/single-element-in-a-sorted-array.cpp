class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int h=n-1;
        
        while(l<h){
            int m=l+(h-l)/2;
            if(m%2!=0){
                m=m-1;
            }
            if(nums[m]!=nums[m+1]){
                h=m;
            }
            else {
                l=m+2;
            }
        }
        return nums[l];

        
    }
};