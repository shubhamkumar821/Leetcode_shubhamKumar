class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
             

             map<string,int>mpp;
             for(auto i:nums){
                mpp[i]++;
             }
             int n=nums[0].size();
             string t="";
        

             for(int i=0;i<(1<<n);i++){
                string s="";

            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    s+='1';

                }
                else{
                    s+='0';
                }
            }
            if(mpp[s]){
                continue;
            }
            else{
                return s;
            }
                

             }
             return t;




        
    }
};