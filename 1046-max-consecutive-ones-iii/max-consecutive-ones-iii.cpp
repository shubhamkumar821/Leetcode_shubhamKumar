class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int head=-1;
        int tail=0;
        int n=nums.size();
        int cnt=0;
        int ans=0;
        while(tail<n){
            while(head+1<n &&((nums[head+1]==1 && cnt<=k )|| (nums[head+1]==0 && cnt<k))){
                head++;
                if(nums[head]==0){
                    cnt++;
                }
            }
            ans=max(ans,head-tail+1);
            if(tail<=head){
                if(nums[tail]==0)
                cnt--;
                tail++;
            }
            else{
                tail++;
                head=tail-1;
            }
        }
        return ans;
        
    }
};