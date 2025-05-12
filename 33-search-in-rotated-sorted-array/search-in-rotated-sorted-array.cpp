class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;

            if(check(mid,nums,target))
            {
              ans=mid;
              r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        int x=serachit(nums, target,0,ans-1);
        int y=serachit( nums, target,ans,nums.size()-1);

        if(x==-1){
        if(y==-1){
            return -1;
        }
        else {
            return y;
        }
    }
    else{
       return x;
    }
        
    }
    int serachit(vector<int>& nums, int target,int l,int r){
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                ans=mid;
                return ans;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else {
                l=mid+1;
            }

        }
        return ans;
    }
    bool check(int x,vector<int>&nums,int target){
        if((nums[nums.size()-1]>=nums[x]))
        return 1;
        else return 0;
    }
};