class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        int n=s.size();
        int cnt=0;
        string t="";
        if(n==1){
            return "1";
        }
        for(auto i: s){
            if(i=='1'){
                cnt++;
            }
        }
        if(cnt==1){
            for(int i=0;i<n;i++){
                if(i!=n-1){
                    t+='0';
                }
                else{
                    t+='1';
                }
            }
        }

        else{
            for(int i=0;i<cnt-1;i++){
                t+='1';
            }
            for(int i=cnt-1;i<n;i++){
                if(i!=n-1){
                    t+='0';
                }
                else{
                    t+='1';
                }
            }
        }
        return t;
        
    }
};