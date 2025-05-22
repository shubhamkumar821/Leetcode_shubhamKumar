class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans[i]=sum;
        }
        for(int i=0;i<n;i++){
            if(i==0){
                if(ans[n-1]-ans[0]==0){
                    return i;
                }

            }
            else{
                if(ans[i-1]==ans[n-1]-ans[i]){
                    return i;
                }

            }
        }
        return -1;
        
    }
};