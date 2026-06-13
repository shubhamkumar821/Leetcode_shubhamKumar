class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long prod=1;
        int ans=0;
        int n=nums.size();
        int head=0;
        if(k==0  || k==1){
            return 0;
        }
        

        for(int tail=0,head=0;head<n;head++){
            prod*=nums[head];
            while(prod>=k){
                prod/=nums[tail];
                tail++;
                
                

            }
            ans+=head-tail+1;
            

        }
        return ans;
        
    }
};