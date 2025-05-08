class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atmost(nums,goal)-atmost(nums,goal-1); 
        
    }

    int atmost(vector<int>& nums,int goal){
        int n=nums.size();
        int head=-1;
        int tail=0;
        int sum=0;
        int ans=0;
        while(tail<n)
        { 

            while(head+1<n && ( nums[head+1]+sum<=goal)){
                head++;
                sum+=nums[head];

            }
            ans+=head-tail+1;
            if(tail>head){
                tail++;
                head=tail-1;

            }
            else{
                sum-=nums[tail];
                tail++;
            }
        }
        return ans;
    }
};