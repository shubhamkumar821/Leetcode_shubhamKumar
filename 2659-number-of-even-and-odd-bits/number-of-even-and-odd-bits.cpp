class Solution {
public:
    vector<int> evenOddBit(int n) {
        int oddcount=0;
        int evencount=0;
        vector<int> ans;
        int k=n;
        int m=n;
        while(k!=0){
            if(k&1){
         evencount++;
            }
            k=k>>2;
        }
        m=m>>1;
           while(m!=0){

            if(m&1){
         oddcount++;
            }
            m=m>>2;
        }
        ans.push_back(evencount);
         ans.push_back(oddcount);
         return ans;
        
        
    }
};