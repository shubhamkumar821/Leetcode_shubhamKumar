class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    
      int head=-1;
        int tail=0;
        int n=nums.size();
        int sum=0;
       int  ans=n;
       bool myans=true;
        while(tail<n){
            while(head+1<n && sum<target){
                head++;
                sum+=nums[head];
            }
       if(sum>=target)     {
        myans=false;
        
        ans=min(ans,head-tail+1);
       }
        if(head>=tail){
            sum-=nums[tail];
            tail++;
        }
        else {
            tail++;
            head=tail-1;
        }

        }
        if(myans)
            return 0;
            return ans;
        
        
        
    }
};