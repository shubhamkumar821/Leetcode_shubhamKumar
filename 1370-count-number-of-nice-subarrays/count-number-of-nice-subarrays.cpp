class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
     
    }
    int func(vector<int>& nums, int k){
           int tail=0;
        int head=-1;
        int ans=0;
        int cntodd=0;  
        while(tail<nums.size()){
            while(head+1<nums.size() && (cntodd<k || nums[head+1]%2==0) ){
                head++;
                if(nums[head]%2!=0){
                    cntodd++;
                }
            } 
               ans+=head-tail+1;
        
            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                if(nums[tail]%2!=0){
                    cntodd--;
                }
                tail++;

            }
        }
      return ans;  
    }
};