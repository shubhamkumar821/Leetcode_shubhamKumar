class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int  n=nums.size();
        int ans=0;
        for(int j=0;j<n;j++){
            int ev=0,od=0;
            map<int,int>mpp;
        for(int i=j;i<n;i++){

            if(mpp[nums[i]]==0){
                if(nums[i]&1){
                    od++;
                }
                else{
                    ev++;
                }
                mpp[nums[i]]++;
            }
            if(ev==od){
                ans=max(ans,i+1-j);

            }
            

        }
        }
        return ans;
        
    }
};