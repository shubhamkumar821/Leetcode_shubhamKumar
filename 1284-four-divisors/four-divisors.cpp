class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
       int res=0;
         for(int j=0;j<nums.size();j++){
            vector<int>st;
        for(int i=1;i*i<=nums[j];i++){
            if(nums[j]%i==0){
                st.push_back(i);
             if(i*i!=nums[j]){
                st.push_back(nums[j]/i);
             }
                
             }
           
        }
         if(st.size()==4){
            for(auto i:st){
                res+=i;
            }
                
            }
         }

         
        
         return res;
        
    }
};