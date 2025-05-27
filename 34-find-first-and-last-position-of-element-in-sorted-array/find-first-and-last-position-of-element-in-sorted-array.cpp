class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return {func1(nums,target),func2(nums,target)};
    }
    int func1(vector<int>& nums, int target){
        int n=nums.size();
        int l=0;
        int h=n-1;
        int ans=-1;
        while(l<=h){
            int mid=(h-l)/2+l;
            if(nums[mid]==target){
                ans=mid;
                h=mid-1;
                
            }
            else if(target>nums[mid]){
                l=mid+1;

            }
            else {
                h=mid-1;

            }
        }
        return ans;
    }
     int func2(vector<int>& nums, int target){
        int n=nums.size();
        int l=0;
        int h=n-1;
        int ans=-1;
        while(l<=h){
            int mid=(h-l)/2+l;
            if(nums[mid]==target){
                ans=mid;
                l=mid+1;
                
            }
            else if(target>nums[mid]){
                l=mid+1;

            }
            else {
                h=mid-1;

            }
        }
        return ans;
    }
    
};