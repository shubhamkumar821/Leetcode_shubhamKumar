class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int i=0;int j=0;
        int ans=0;
        int n=nums.size();
        int mask=0;
        while(i<n){
            
            while((mask & nums[i])!=0){
                mask^=nums[j];
                j++;

            }

            mask|=nums[i];

            ans=max(ans,i-j+1);
            i++;
        
        }
        return ans;
        
    }
};