class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
    
        sort(nums.begin(),nums.end());
        int x=INT_MAX;
        for(int i=0;i<=n-k;i++){
            int ans=0;
            for(int j=i;j<i+k-1;j++){
                ans+=(nums[j+1]-nums[j]);
            }
            x=min(x,ans);
        }
        return x;
      
    }
};