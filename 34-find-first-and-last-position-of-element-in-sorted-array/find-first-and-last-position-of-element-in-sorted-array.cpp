class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {


        int l=0;
        int h=nums.size()-1;
        int ans1=-1;
        while(l<=h){
            long long mid=(l+h)/2;
            if(target==nums[mid]){
                ans1=mid;
                h=mid-1;
            }
            else if(nums[mid]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        int ans2=-1;
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            long long mid=(s+e)/2;
            if(target==nums[mid]){
                ans2=mid;
                s=mid+1;
            }
            else if(target>nums[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }

        }
        vector<int>ans;
        ans.push_back(ans1);
        ans.push_back(ans2);

return ans;

        
    }

};