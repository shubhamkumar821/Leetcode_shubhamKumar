class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int cnt=0,ans=0;
        if(nums.empty()){
            return 0;
        }
    if(nums.size()==1){
        return 1;
    }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1){
                cnt++;
            }
            ans=max(ans,cnt);
            if(nums[i+1]-nums[i]==0){
                continue;
            }
            if((nums[i+1]-nums[i])>1){
                cnt=0;
                
            }
        }
        return ans+1;

        
    }
};