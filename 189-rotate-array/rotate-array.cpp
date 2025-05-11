class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=nums[i];
        }
        for(int i=0;i<k;i++){
            nums[i]=ans[n-k+i];
        }
        for(int i=k;i<n;i++){
            nums[i]=ans[i-k];
        }
        
    }
};