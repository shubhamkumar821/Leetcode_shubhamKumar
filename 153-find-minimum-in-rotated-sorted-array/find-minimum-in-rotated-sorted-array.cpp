class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(check(nums,m)){
                ans=m;
                h=m-1;
            }
            else {
                l=m+1;
            }
            
        }
        return nums[ans];

        
    }
    bool check(vector<int>& nums,int x){
        if(nums[nums.size()-1]>=nums[x])
        return true;
        else return false ;
    }
};