class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int ans=nums.size();
    while(l<=r){
        int m=(l+r)/2;
        if(check(m,nums,target)){
            ans=m;
            r=m-1;

        }
        else{
            l=m+1;
        }
    }
    return ans;

        
    }
    bool check(int x,vector<int>& nums,int target){
        if(nums[x]>=target){
            return true;
        }
        return false;
    }
};