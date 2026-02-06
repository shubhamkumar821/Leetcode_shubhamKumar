class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int j=0;
        int i=0;
        int n=nums.size();
        int ans=0;
    
        while(i<n && j<n){
while (i < n && nums[i] <= 1LL * nums[j] * k) {
    i++;
}
              ans=max(ans,i-j);

       j++;
}

  int sz=n-ans;
        return sz;
       


        }

       
       
    
};