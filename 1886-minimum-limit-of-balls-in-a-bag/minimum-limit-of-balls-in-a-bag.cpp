class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxi=INT_MIN;
        for(auto i:nums){
            maxi=max(maxi,i);
        }
        int h=maxi;
        int l=1;
        int ans=h;
        

        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(mid,nums,maxOperations)){
                ans=mid;
                h=mid-1;

            }

            else{
                l=mid+1;

            }
        }
        return ans;
        
    }

    bool check(int x, vector<int>& nums, int k) {
    int operations = 0;

    for(int i : nums) {
        operations += (i - 1) / x;

        if(operations > k)
            return false;
    }

    return true;
}
};