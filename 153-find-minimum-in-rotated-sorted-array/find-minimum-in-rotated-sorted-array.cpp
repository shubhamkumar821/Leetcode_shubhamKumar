class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int val=nums[h];
        int ans=-1;

        while(l<=h){
            int mid=(l+h)/2;

            if(nums[mid]<=val){
                ans=mid;
                h=mid-1;
            }
            else {
                l=mid+1;

            }

        }
        return nums[ans];
        
    }
};