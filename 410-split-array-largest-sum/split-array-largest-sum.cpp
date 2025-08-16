class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int h=accumulate(nums.begin(),nums.end(),0);
      int  ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid,nums,k)){
                ans=mid;
                h=mid-1;
            }
            else{
       l=mid+1;
            }

        }
        return ans;
        
    }
    bool check(int mid,vector<int>&arr,int k){
        int sum_left=0;
        int no_of_window=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=sum_left){
                sum_left-=arr[i];
            }
            else{
                no_of_window++;
                if(no_of_window>k){
                    return false;
                }
                sum_left=mid;

                if(arr[i]>sum_left){
                    return false;

                }
                else{
                    sum_left-=arr[i];
                }
            }
        }
        return true;
    }
};