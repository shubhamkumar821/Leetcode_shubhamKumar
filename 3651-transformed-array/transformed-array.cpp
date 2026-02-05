class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int>results(nums.size());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int k=nums[i];
                k=(i+k)%n;
                results[i]=nums[k];

            }
            else if(nums[i]<0){
                int k=abs(nums[i]);
                  k= (n-(k%n -i))%n;
                results[i]=nums[k];

            }

            else{
                results[i]=nums[i];

            }
        }
        return results;
        
    }
};