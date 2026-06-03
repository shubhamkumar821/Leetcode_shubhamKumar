class Solution {
public:
    int search(vector<int>& nums, int target) {


        int ans=-1;
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            long long  mid=(l+r)/2;

            if(nums[mid]==target){
                ans=mid;
                return ans;
            }
            else if(nums[mid]>target){
                r=mid-1;

            }
            else{
                l=mid+1;

            }

        }
        return ans;
        
    }
};