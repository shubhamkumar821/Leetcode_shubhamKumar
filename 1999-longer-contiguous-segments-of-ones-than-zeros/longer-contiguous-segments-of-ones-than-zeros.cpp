class Solution {
public:
    bool checkZeroOnes(string s) {
        int cnt1=0,cnt0=0;
        int ans1=0,ans0=0;
        for(int i:s){
            if(i=='1'){
                cnt1++;
            }
            else{
                cnt1=0;
            }
        ans1=max(ans1,cnt1);
        }
          for(int i:s){
            if(i=='0'){
                cnt0++;
            }
            else{
                cnt0=0;
            }
        ans0=max(ans0,cnt0);
        }

        return ans1>ans0;
        
    }
};